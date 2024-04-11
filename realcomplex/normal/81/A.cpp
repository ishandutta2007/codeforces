#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	string ans;
	for(int j = 0;j<s.size();j++){
		ans+=s[j];
		if(ans.size()>=2){
			if(ans[ans.size()-1]==ans[ans.size()-2])ans.erase(ans.size()-2,2);
		}
	}
	cout << ans;
	return 0;
}