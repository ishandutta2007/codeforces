#include <iostream>
#include <numeric>
#include <string>
typedef long long ll;
using namespace std;

bool check(string m, string s, string t){
	for(int i=0;i<m.size()-1;i++){
		if((m[i] == s[0] && m[i+1] == s[1]) || (m[i] == t[0] && m[i+1] == t[1])){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	cout << "YES" << endl;
	if(s[0] == s[1] && t[0] == t[1]){
		for(int i=0;i<n;i++){
			cout << "abc";
		}
	}else if(s[0] != s[1] && t[0] != t[1]){
		if(s == t){
			t[1] = (char)((int)'a' + 'b' + 'c' - s[1] - t[0]);
		}
		if(s[0] == t[0]){
			for(int i=0;i<n;i++){
				cout << s[1] << t[1];
			}
			for(int i=0;i<n;i++){
				cout << s[0];
			}
		}else if(s[1] == t[1]){
			for(int i=0;i<n;i++){
				cout << s[1];
			}
			for(int i=0;i<n;i++){
				cout << s[0] << t[0];
			}
		}else{
			for(string i : {"abc", "acb", "bac", "bca", "cab", "cba"}){
				bool res = check(i, s, t);
				if(res){
					for(char j : i){
						for(int k=0;k<n;k++){
							cout << j;
						}
					}
					break;
				}
			}
		}
	}else{
		if(t[0] == t[1]){
			swap(s, t);
		}
		for(string i : {"abca", "acba", "bacb", "bcab", "cabc", "cbac"}){
			bool res = check(i, s, t);
			if(res){
				for(int j=0;j<n;j++){
					cout << i.substr(0, 3);
				}
				break;
			}
		}
	}
}