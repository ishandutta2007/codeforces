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
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int a[1<<21],lson[1<<21],rson[1<<21];
bool ok[1<<21];
int n,m;
ll ans=0;
int pos[1<<21],cnt;
void build(){
	rep(i,1,1<<n-1)if(a[lson[i]]<a[rson[i]])swap(lson[i],rson[i]);
}
void upd(int u){
	if(!a[u]){
		ok[u]=0;
		return;
	}
	a[u]=a[lson[u]];
	upd(lson[u]);
	if(!a[u]){
		ok[u]=0;
		return;
	}
	if(a[lson[u]]<a[rson[u]]){
		swap(lson[u],rson[u]);
	}
	if(!ok[lson[u]])ok[u]=0;
	if(a[u]&&(u>=(1<<m)))ok[u]=1;
//	cout<<u<<' '<<a[u]<<' '<<ok[u]<<' '<<lson[u]<<"check\n";
}
void solve(int u){
	if(!a[u])return;
	while(ok[u]){
		pos[cnt++]=u;
		ans-=a[u];
		upd(u);
	//	cout<<"OK\n";
	}
	solve(lson[u]);
	solve(rson[u]);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		cnt=0,ans=0;
		scanf("%d%d",&n,&m);
		rep(i,1,1<<n)scanf("%d",&a[i]),lson[i]=i<<1,rson[i]=i<<1|1,ans+=a[i],ok[i]=1;
		rep(i,1<<n,1<<n+1)ok[i]=0,a[i]=0;
		build();
		solve(1);
		printf("%lld\n",ans);
		rep(i,0,cnt)printf("%d ",pos[i]);
		printf("\n");
	}
}