#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int pre[105];
int suf[105];

int main(){
	string s;
	cin >> s;
	for(int i = 0;i<s.size();i++){
		pre[i]+=(s[i]=='Q');
		suf[i]+=(s[i]=='Q');
	}
	for(int j = s.size()-2;j>=0;j--){
		suf[j]+=suf[j+1];
	}
	for(int j = 1;j<s.size();j++){
		pre[j]+=pre[j-1];
	}	
	ll ans = 0;
	for(int j = 0;j<s.size();j++){
		if(s[j]=='A'){
			ans += pre[j-1]*suf[j+1]*1LL;
		}
	}	
	cout << ans << "\n";
	return 0;
}