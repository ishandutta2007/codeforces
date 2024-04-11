#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int ans=min(n,m)+1;
	cout<<ans<<'\n';
	for(int i=1;i<=ans;i++){
		cout<<i-1<<' '<<ans-i<<'\n';
	}
	return 0;
}