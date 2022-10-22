#include <bits/stdc++.h>
using namespace std;
int main(){
	int l,r,n,mini=1000000000,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>l>>r;
		mini=min(mini,r-l+1);
	}
	cout<<mini<<'\n';
	for(int i=1;i<=n;i++)cout<<i%mini<<' ';
	return 0;
}