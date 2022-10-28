#include "bits/stdc++.h"
using namespace std;
string str;
map < char , char > mp;
void pre(){
	mp.clear();
	mp['A'] = 'A';
	mp['b'] = 'd';
	mp['d'] = 'b';
	mp['H'] = 'H';
	mp['I'] = 'I';
	mp['M'] = 'M';
	mp['O'] = 'O';
	mp['o'] = 'o';
	mp['p'] = 'q';
	mp['q'] = 'p';
	for(char c = 'T' ; c <= 'Y' ; ++c){
		mp[c] = c;
	}
	for(char c = 'v' ; c <= 'x' ; ++c){
		mp[c] = c;
	}
}
int main(){
	pre();
	cin >> str;
	int l = 0;
	int r = str.size() - 1;
	while(l <= r){
		if(mp[str[l]] != str[r]){
			cout << "NIE\n";
			return 0;
		}
		++l;
		--r;
	}
	cout << "TAK\n";
}