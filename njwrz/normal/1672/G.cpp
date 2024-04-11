#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
const int mod=998244353;
int n,m;char c[2005][2005],t[2005][2005];
int val[4005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
} 
struct DSU{
	int fa[4005],p[4005],siz[4005],tp[4005];
	void init(int n){
		FOR(i,1,n)fa[i]=i,tp[i]=1;
	}
	int get(int x){
		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
	}
	void merge(int x,int y){
		x=get(x);y=get(y);
		fa[x]=y;
		if(x!=y)siz[y]+=siz[x],p[y]^=p[x],siz[y]--,tp[y]+=tp[x];
		siz[y]++;
	}
}T;
int pw[4000005],cnt[4005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c[i][j];
		}
	}
	if(!(n&1)&&!(m&1)){
		int ans=1;
		FOR(i,1,n)FOR(j,1,m)if(c[i][j]=='?')ans=ans*2%mod;
		cout<<ans;RE 0;
	}
	pw[0]=1;
	FOR(i,1,n*m)pw[i]=pw[i-1]*2%mod;
	if((n&1)&&(m&1)){
		FOR(i,1,n)FOR(j,1,m){
			if(c[i][j]=='1'){
				T.p[i]^=1;T.p[j+n]^=1;
			}
		}
		T.init(n+m);
		FOR(i,1,n)FOR(j,1,m)if(c[i][j]=='?'){
			T.merge(i,j+n);
		}
		int ans=0;
		rep(k,0,2){
			int now=1;
			FOR(i,1,n+m)if(T.get(i)==i){
				if(T.tp[i]*k%2!=T.p[i]){
					now=0;break;
				}
				now=now*pw[T.siz[i]]%mod;
			}
			add(ans,now);
		}
		cout<<ans;RE 0;
	}
	if(m&1){
		FOR(i,1,n)FOR(j,1,m)t[j][i]=c[i][j];
		swap(n,m);
		FOR(i,1,n)FOR(j,1,m)c[i][j]=t[i][j];
	}
	FOR(i,1,n)FOR(j,1,m){
		if(c[i][j]=='1'){
			T.p[i]^=1;T.p[j+n]^=1;
			
		}else if(c[i][j]=='?')cnt[j]++;
	}
	int ans=0;
	rep(k,0,2){
		int now=1;
		FOR(j,1,m){
			if(!cnt[j]){
				if(T.p[j+n]!=k){
					now=0;break;
				}
			}else now=now*pw[cnt[j]-1]%mod;
		}
		add(ans,now);
	}
	cout<<ans;
	RE 0;
}