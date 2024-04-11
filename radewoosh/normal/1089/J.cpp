#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair<m,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c &){ris;}
	#endif
	muu & operator()(){ris;}
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": " )

int R;
vector<string> reserved;

string aux;
char s[90 * 40 + 7];
char wynik[90 * 40 + 77];
int wpos;
int spos = 0;

void readReserved() {
	stringstream sin(aux);
	string x;
	while (sin >> x) {
		reserved.push_back(x);
	}
}

vector<string> tokenize() {
	int pos = 0;
	vector<string> res;
	while (pos < spos) {
		if (s[pos] == ' ') pos++;
		else {
			int naj = 0;
			for (string &str : reserved) {
				bool ok = 1;
				int j = pos;
				for (char z : str) {
					if (s[j] != z) {
						ok = 0;
						break;
					}
					j++;
				}
				
				if (ok) naj = max(naj, (int) str.length());
			}
			
			if (isdigit(s[pos])) {
				int j = pos;
				while (isdigit(s[j])) j++;
				naj = max(naj, j - pos);
			}
			else {
				int j = pos;
				while (isdigit(s[j]) || isalpha(s[j]) || s[j] == '_' || s[j] == '$') j++;
				naj = max(naj, j - pos);
			}
			
			string r;
			while (naj--) {
				r.push_back(s[pos++]);
			}
			res.push_back(r);
		}
	}
	return res;
}

string wordList = string("a");

string nextWord() {
	string res = wordList;
	wordList[0]++;
	int j = 0;
	while (wordList[j] > 'z') {
		wordList[j] = 'a';
		j++;
		if (j == (int) wordList.size()) {
			wordList.push_back('a');
			break;
		}
		else wordList[j]++;
	}
	
	reverse(res.begin(), res.end());
	
	
	
	return res;
}

int main() {
	cin >> R;
	getline(cin, aux);
	getline(cin, aux);

	readReserved();
	debug << imie(reserved);

	int m;
	cin >> m;
	getline(cin, aux);
	while (m--) {
		getline(cin, aux);
		bool wyl = 0;
		for (char c : aux) {
			if (c == '#') wyl = 1;
			if (!wyl) s[spos++] = c;
		}
		s[spos++] = ' ';
	}
	
	debug << imie(s);
	
	vector<string> tokens = tokenize();
	
	debug << imie(tokens);
	
	map<string, string> mapa;
	
	set<string> secik;
	for (string &str : reserved) {
		mapa[str] = str;
		secik.insert(str);
	}
	
	for (string &str : tokens) {
		if (isdigit(str[0])) continue;
		
		if (mapa.find(str) == mapa.end()) {
			string rr = nextWord();
			while (secik.find(rr) != secik.end()) rr = nextWord();
			mapa[str] = rr;
		}
		
		str = mapa[str];
	}
	
	debug << imie(tokens);
		
	reverse (tokens.begin(), tokens.end());
	
	int granica = 90 * 40 + 70;
	wpos = granica;
	wynik[wpos--] = ' ';
	
	for (string &str : tokens) {
		int l = str.length();
		for (int j = 0; j < l; ++j) wynik[wpos - l + 1 + j] = str[j];
	
		int pos = wpos - l + 1;
		
		int naj = 0;
		for (string &st : reserved) {
			bool ok = 1;
			int j = pos;
			for (char z : st) {
				if (wynik[j] != z) {
					ok = 0;
					break;
				}
				j++;
			}
			
			if (ok) naj = max(naj, (int) st.length());
		}
		
		int maxi = l + 2;
		
		if (isdigit(wynik[pos])) {
			int j = pos;
			while (isdigit(wynik[j]) && j - pos < maxi) j++;
			naj = max(naj, j - pos);
		}
		else {
			int j = pos;
			while ((isdigit(wynik[j]) || isalpha(wynik[j]) || wynik[j] == '_' || wynik[j] == '$') && j - pos < maxi) j++;
			naj = max(naj, j - pos);
		}
		
		if (naj > l) {
			wynik[wpos] = ' ';
			wpos--;
			for (int j = 0; j < l; ++j) wynik[wpos - l + 1 + j] = str[j];
		}
		
		wpos -= l;
	}
	
	for (int i = wpos + 1; i < granica; ++i) putchar(wynik[i]);
	putchar('\n');
	return 0;
}