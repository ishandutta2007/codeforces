						/* in the name of Allah */
#include<iostream>
#include<string>
using namespace std;

string s[3];

bool win(char ch){
	if(s[0][0] == ch && s[1][1] == ch && s[2][2] == ch)
		return true;
	if(s[0][2] == ch && s[1][1] == ch && s[2][0] == ch)
		return true;
	for(int i = 0; i < 3; i++){
		bool f = true;
		for(int j = 0; j < 3; j++)
			if(s[i][j] != ch)
				f = false;
		if(f) return true;
	}
	for(int i = 0; i < 3; i++){
		bool f = true;
		for(int j = 0; j < 3; j++)
			if(s[j][i] != ch)
				f = false;
		if(f) return true;
	}
	return false;
}

int main(){
	int c1 = 0, c2 = 0;
	bool w1, w2;
	for(int i = 0; i < 3; i++){
		cin >> s[i];
		for(int j = 0; j < 3; j++){
			if(s[i][j] == 'X') c1++;
			if(s[i][j] == '0') c2++;
		}
	}
	w1 = win('X'), w2 = win('0');
	if((c1 != c2 && c1 - 1 != c2) || (w1 && w2))
		cout << "illegal" << endl;
	else if((w1 && c1 == c2) || (w2 && c1 - 1 == c2))
		cout << "illegal" << endl;
	else if(w1) cout << "the first player won" << endl;
	else if(w2) cout << "the second player won" << endl;
	else if(c1 + c2 == 9)
		cout << "draw" << endl;
	else cout << (c1 == c2 ? "first" : "second") << endl;
}