#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,i,a,b;
pair<int,int>ee[N];
int ans[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	if(m==1ll*n*(n-1)/2){cout<<"NO\n";return 0;}
	for(i=1;i<=m;++i){
		cin>>a>>b;
		if(a>b)swap(a,b);
		ee[i]=make_pair(a,b);
	}
	sort(ee+1,ee+m+1);
	a=1;b=2;
	for(i=1;i<=m;++i){
		if(ee[i].first!=a || ee[i].second!=b)break;
		if(++b>n)++a,b=a+1;
	}
	ans[a]=1;ans[b]=2;int w=2;
	for(i=1;i<=n;++i)if(!ans[i])ans[i]=++w;
	cout<<"YES\n";
	for(i=1;i<=n;++i)cout<<ans[i]<<' ';cout<<'\n';
	ans[b]=1;
	for(i=1;i<=n;++i)cout<<ans[i]<<' ';cout<<'\n';
	return 0;
}