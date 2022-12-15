#include <bits/stdc++.h>
using namespace std;

struct Block {
	bool estAtome;
	vector<string> grille;
};

Block arrow, S, F;

Block concatH(const Block a, const Block b) {
	Block res;
	res.estAtome = a.estAtome && b.estAtome;

	res.grille = vector<string>(
		max(a.grille.size(), b.grille.size()),
		string(
			a.grille[0].size() + b.grille[0].size(),
			' '
		)
	);

	for(size_t i = 0;i < a.grille.size();i++)
		for(size_t j = 0;j < a.grille[0].size();j++)
			res.grille[i][j] = a.grille[i][j];
	
	for(size_t i = 0;i < b.grille.size();i++)
		for(size_t j = 0;j < b.grille[0].size();j++)
			res.grille[i][j + a.grille[0].size()] = b.grille[i][j];

	return res;
}

Block entoure(Block a) {
	Block res;
	res.estAtome = false;

	res.grille = vector<string>(
		a.grille.size() + 2,
		string(
			a.grille[0].size() + 4,
			' '
		)
	);

	for(size_t i = 0;i < a.grille.size();i++)
		for(size_t j = 0;j < a.grille[0].size();j++)
			res.grille[i + 1][j + 2] = a.grille[i][j];
	
	for(size_t j = 0;j < res.grille[0].size();j++) {
		res.grille[0][j] = '-';
		res.grille[res.grille.size() - 1][j] = '-';
	}
	
	for(size_t i = 0;i < res.grille.size();i++) {
		res.grille[i][0] = '+';
		res.grille[i][res.grille[0].size() - 1] = '+';
	}

	return res;
}

Block block_plus(Block a) {
	a = concatH(concatH(arrow, a), arrow);
	Block res;
	res.estAtome = false;

	res.grille = vector<string>(
		a.grille.size() + 2,
		string(
			a.grille[0].size() + 2,
			' '
		)
	);

	for(size_t i = 0;i < a.grille.size();i++)
		for(size_t j = 0;j < a.grille[0].size();j++)
			res.grille[i][j + 1] = a.grille[i][j];
	
	for(size_t j = 0;j < res.grille[0].size();j++) {
		res.grille[res.grille.size() - 1][j] = '-';
	}
	
	for(size_t i = 1;i < res.grille.size();i++) {
		res.grille[i][0] = '|';
		res.grille[i][res.grille[0].size() - 1] = '|';
	}

	res.grille[1][0] = '+';
	res.grille[res.grille.size() - 1][0] = '+';
	res.grille[1][res.grille[0].size() - 1] = '+';
	res.grille[res.grille.size() - 1][res.grille[0].size() - 1] = '+';
	res.grille[res.grille.size() - 1][1] = '<';

	return res;
}

Block block_question(Block a) {
	a = concatH(concatH(arrow, a), arrow);
	Block res;
	res.estAtome = false;

	res.grille = vector<string>(
		a.grille.size() + 3,
		string(
			a.grille[0].size() + 2,
			' '
		)
	);

	for(size_t i = 0;i < a.grille.size();i++)
		for(size_t j = 0;j < a.grille[0].size();j++)
			res.grille[i + 3][j + 1] = a.grille[i][j];
	
	for(size_t j = 0;j < res.grille[0].size();j++) {
		res.grille[1][j] = '-';
	}
	
	for(size_t i = 1;i < 4;i++) {
		res.grille[i][0] = '|';
		res.grille[i][res.grille[0].size() - 1] = '|';
	}

	res.grille[1][0] = '+';
	res.grille[4][0] = '+';
	res.grille[1][res.grille[0].size() - 1] = '+';
	res.grille[4][res.grille[0].size() - 1] = '+';
	res.grille[1][res.grille[0].size() - 2] = '>';

	return res;
}

Block block_star(Block a) {
	a = concatH(concatH(arrow, a), arrow);
	Block res;
	res.estAtome = false;

	res.grille = vector<string>(
		a.grille.size() + 5,
		string(
			a.grille[0].size() + 2,
			' '
		)
	);

	for(size_t i = 0;i < a.grille.size();i++)
		for(size_t j = 0;j < a.grille[0].size();j++)
			res.grille[i + 3][j + 1] = a.grille[i][j];
	
	for(size_t j = 0;j < res.grille[0].size();j++) {
		res.grille[1][j] = '-';
		res.grille[res.grille.size() - 1][j] = '-';
	}
	
	for(size_t i = 1;i < res.grille.size() - 1;i++) {
		res.grille[i][0] = '|';
		res.grille[i][res.grille[0].size() - 1] = '|';
	}

	res.grille[1][0] = '+';
	res.grille[res.grille.size() - 1][0] = '+';
	res.grille[4][0] = '+';
	res.grille[1][res.grille[0].size() - 1] = '+';
	res.grille[res.grille.size() - 1][res.grille[0].size() - 1] = '+';
	res.grille[4][res.grille[0].size() - 1] = '+';
	res.grille[1][res.grille[0].size() - 2] = '>';
	res.grille[res.grille.size() - 1][1] = '<';

	return res;
}

void affiche(Block b) {
	cout << b.grille.size() << " " << b.grille[0].size() << endl;
	for(string s : b.grille) {
		cout << s << endl;
	}
}

int pos = 0;
string rgx;

Block atome(char x) {
	Block res;
	res.estAtome = true;
	res.grille.push_back(string(1, x));
	return res;
}

Block block_seq(vector<Block> xs) {
	vector<Block> ys;
	for(Block x : xs) {
		if(ys.empty() || ys.back().grille.size() > 1 || x.grille.size() > 1) {
			ys.push_back(x);
		}
		else {
			ys.back() = concatH(ys.back(), x);
		}
	}
	xs = ys;
	ys.clear();

	for(Block x : xs) {
		if(x.estAtome)
			ys.push_back(entoure(x));
		else
			ys.push_back(x);
		
		//affiche(ys.back());
	}
	xs = ys;
	ys.clear();

	if(xs.size() == 1)
		return xs[0];

	Block res = xs[0];

	for(size_t i = 1;i < xs.size();i++)
		res = concatH(concatH(res, arrow), xs[i]);
	
	return res;
}

Block block_or(vector<Block> xs) {
	if(xs.size() == 1)
		return xs[0];
	
	vector<Block> ys;
	for(Block x : xs)
		ys.push_back(concatH(arrow, x));
	xs = ys;
	ys.clear();

	Block res;
	res.estAtome = false;

	int height = -1, width = 0;
	for(Block x : xs) {
		width = max(width, (int)x.grille[0].size() + 4);
		height += x.grille.size() + 1;
	}

	res.grille = vector<string>(
		height,
		string(
			width,
			' '
		)
	);
	
	height = 0;
	for(Block x : xs) {
		for(size_t i = 0;i < x.grille.size();i++)
			for(size_t j = 0;j < x.grille[0].size();j++)
				res.grille[i + height][j + 1] = x.grille[i][j];
		
		for(int j = x.grille[0].size() + 1;j < (int)res.grille[0].size() - 1;j++) {
			res.grille[height + 1][j] = '-';
		}
		res.grille[height + 1][res.grille[0].size() - 2] = '>';

		for(int i = 1;i <= height + 1;i++) {
			res.grille[i][0] = '|';
			res.grille[i][res.grille[0].size() - 1] = '|';
		}

		height += x.grille.size() + 1;
	}

	height = 0;
	for(Block x : xs) {
		res.grille[height + 1][0] = '+';
		res.grille[height + 1][res.grille[0].size() - 1] = '+';

		height += x.grille.size() + 1;
	}

	return res;
}


Block parse_letter();
Block parse_seq();
Block parse_expr();


Block parse_letter() {
	Block res = atome(rgx[pos]);
	pos++;

	while(rgx[pos] == '*' || rgx[pos] == '?' || rgx[pos] == '+') {
		if(res.estAtome)
			res = entoure(res);
		if(rgx[pos] == '*')
			res = block_star(res);
		if(rgx[pos] == '+')
			res = block_plus(res);
		if(rgx[pos] == '?')
			res = block_question(res);
		pos++;
	}

	return res;
}

Block parse_seq() {
	vector<Block> blocks;

	while(rgx[pos] != '|' && rgx[pos] != ')') {
		if(rgx[pos] == '(')
			blocks.push_back(parse_expr());
		else
			blocks.push_back(parse_letter());
	}

	return block_seq(blocks);
}

Block parse_expr() {
	pos++;

	vector<Block> blocks;
	blocks.push_back(parse_seq());

	while(rgx[pos] == '|') {
		pos++;
		blocks.push_back(parse_seq());
	}
	
	pos++;

	Block res = block_or(blocks);
	while(rgx[pos] == '*' || rgx[pos] == '?' || rgx[pos] == '+') {
		if(rgx[pos] == '*')
			res = block_star(res);
		if(rgx[pos] == '+')
			res = block_plus(res);
		if(rgx[pos] == '?')
			res = block_question(res);
		pos++;
	}

	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	arrow.estAtome = false;
	arrow.grille = {
		"  ",
		"->"
	};

	S.estAtome = false;
	S.grille = {
		"   ",
		"S->"
	};

	F.estAtome = false;
	F.grille = {
		"   ",
		"->F"
	};

	cin >> rgx;
	rgx = "(" + rgx + ");";
	affiche(concatH(S, concatH(parse_expr(), F)));

	/*affiche(
		block_seq({
		block_plus(block_question(entoure(concatH(atome('X'),atome('Y'))))),
		atome('X'),
		atome('Y'),
		atome('Z')})
	);*/
	return 0;
}