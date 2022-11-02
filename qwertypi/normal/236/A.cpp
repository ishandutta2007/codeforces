#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
	string s;
	cin >> s;
	set<char> c;
	for(auto i:s){
		c.insert(i);
	}
	if(c.size() % 2){
		cout << "IGNORE HIM!";
	}else{
		cout << "CHAT WITH HER!";
	}
	return 0;
}