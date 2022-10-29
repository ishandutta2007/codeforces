#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
using namespace std;
const int N=1<<18;
const ll mod=998244353;
int cnt[N],fa[N];
int dsu(int x){
	if(fa[x]==x)return x;
	return fa[x]=dsu(fa[x]);
}
ll ans;
void solve(int u,int v){
	if(!cnt[u]||!cnt[v])return;
	if(dsu(u)==dsu(v))return;
	fa[dsu(u)]=dsu(v);
	ans+=1ll*(u|v)*(cnt[u]+cnt[v]-1);
	cnt[u]=1;cnt[v]=1;
}
int main(){
	int n,x;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d",&x);
		ans-=x;
		cnt[x]++;
	}
	cnt[0]++;
	rep(i,0,N)fa[i]=i;
	per(i,0,N){
		for(int j=i;j>(i^j);j=(j-1)&i){
			solve(j,j^i);
		}
	}
	printf("%lld",ans);
}