#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	s = "---"+s;
	for(int i = s.size()-1;i>3;i--){
		if(s[i]!='/')break;
		s.erase(i,1);
	}
	for(int j = 3;j<s.size();j++){
		if(s[j]=='/'){
			if(s[j-1]!='/')cout << "/";
		}
		else{
			cout << s[j];
		}
	}
	cout << endl;
	return 0;
}