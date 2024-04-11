#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,maxi=0,x,mini=1000000000;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		maxi=max(maxi,x);
		cin>>x;
		mini=min(mini,x);
	}
	cout<<max(0,maxi-mini)<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)solve(); 
	return 0;
}