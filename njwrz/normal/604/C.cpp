#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n;
	cin>>n>>s;
	int ans=3;
	for(int i=1;i<n;i++){
		ans+=(s[i]!=s[i-1]);
	}
	cout<<min(ans,n);
	return 0;
}