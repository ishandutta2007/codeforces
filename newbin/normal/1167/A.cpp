#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	int T;cin>>T;
	while(T--){
		int n;
		cin>>n>>s;
		int p = -1;
		for(int i = 0;i < s.size();++i) {
			if(s[i] == '8'){
				p = i;break;
			}
		}
		if(p >= 0 && n - p >= 11) cout<<"YES\n";
		else cout<<"NO\n";
	}
}