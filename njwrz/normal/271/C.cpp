#include <bits/stdc++.h>
using namespace std;
int ans[1000005];
int main(){
	int n,k;
	cin>>n>>k;
	if(k*3>n){
		cout<<-1;return 0;
	}
	for(int i=1;i<=k;i++){
		ans[i*2-1]=ans[i*2]=ans[k*2+i]=i;
	}
	for(int i=k*3+1;i<=n;i++)ans[i]=1;
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}