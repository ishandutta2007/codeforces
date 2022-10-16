#include <cstdio>
#include <iostream>
#include <string>

using namespace std;


string s;
string sol = "";
int n;

int main(){
	cin >> n;
	cin >> s;
	for(int i = 0;i<n;){
		int be = 0;
		int t = 1;
		while((t && s[i+be] == 'o') || (!t && s[i+be] == 'g')){
			t = !t;
			be++;
			if(i == n) break;
		}
		if(be < 3){
			sol += s[i];
			i++;
			continue;
		}
		if(be%2 == 0){
			be--;
			sol += "***";
			i += be;
			continue;
		}
		if(be%2 == 1){
			sol += "***" ;
			i += be;
			continue;
		}
	}
	cout << sol << endl;
	
}