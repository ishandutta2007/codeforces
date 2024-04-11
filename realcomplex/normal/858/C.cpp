#include <bits/stdc++.h>

using namespace std;

set<char>wow;

bool is(string k){
	if((wow.count(k[0])==0&&wow.count(k[1])==0&&wow.count(k[2])==0)&&!(k[0]==k[1]&&k[1]==k[2]))return true;
	else return false;
}

int main(){
	string s;
	cin >> s;
	wow.insert('a');wow.insert('e');wow.insert('i');wow.insert('o');wow.insert('u');
	for(int j = 2;j<s.size();j++){
		if(is(s.substr(j-2,3))){
			cout << s.substr(0,j) << " ";
			s.erase(0,j);
			j = 1;
		}
	}
	cout << s;
	return 0;
}