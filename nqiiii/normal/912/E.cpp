#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=16,maxm=5000000;
int n,p[maxn+10]; ll l=1,r=1e18,k;
ll a[2][maxn+10],b[2][maxm+10];
void dfs(ll x,ll v,int id){
	if(x==a[id][0]+1){
		b[id][++b[id][0]]=v; return;
	}
	if(v>r/a[id][x]) dfs(a[id][0]+1,v,id);
	else{
		for(;v<=r/a[id][x];v*=a[id][x]) dfs(x+1,v,id);
		dfs(x+1,v,id);
	}
}
ll solve(ll v){
	int r=b[1][0]; ll ans=0;
	for(int i=1;i<=b[0][0];++i){
		for(;r&&b[1][r]>v/b[0][i];) --r;
		ans+=r;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]);
	sort(p+1,p+n+1); scanf("%lld",&k);
	for(int i=1;i<=n;++i) a[i&1][++a[i&1][0]]=p[i];
	dfs(1,1,0); dfs(1,1,1);
	for(int i=0;i<=1;++i) sort(&b[i][1],&b[i][b[i][0]]+1);
	for(;l!=r;){
		ll mid=(l+r)/2;
		if(solve(mid)<k) l=mid+1; else r=mid;
	}
	printf("%lld",l); return 0;
}