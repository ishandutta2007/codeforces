#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys1=1000000007,cys2=1019260817;
int n,tn,m;
int lev[1000005],q[1000005],f[1000005][20],b[10],fp[1000005];
ll h1[1000005],h2[1000005];
vector<int> vec;
vector<pii> adj[1000005];

void bfs(){
	memset(lev,-1,sizeof(lev));
	int front=0,rear=0;
	lev[1]=0; q[rear++]=1;
	while(front<rear){
		int t=q[front++];
		vec.pb(t);
		for(auto v:adj[t]){
			if(lev[v.fi]<0){
				lev[v.fi]=lev[t]+1;
				q[rear++]=v.fi;
			}
		}
	}
}

int jump(int x,int d){
	for(int i=19;i>=0;i--) if(d&(1<<i)) x=f[x][i];
	return x;
}

int compare(int x,int y){
	int l=1,r=lev[x],ed=lev[x]+1;
	while(l<=r){
		int mid=(l+r)/2,tx=jump(x,lev[x]-mid),ty=jump(y,lev[y]-mid);
		if(h1[tx]==h1[ty]&&h2[tx]==h2[ty]) l=mid+1;
		else ed=mid,r=mid-1;
	}
	if(ed==lev[x]+1) return 0;
	else{
		int tx=jump(x,lev[x]-ed),ty=jump(y,lev[y]-ed);
		return fp[tx]<fp[ty]?1:-1;
	}
}

int main(){
	tn=n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		int tmp=i,k=0;
		while(tmp) b[++k]=tmp%10,tmp/=10;
		int lst=x;
		for(int j=k;j>=2;j--){
			adj[lst].pb(mp(++tn,b[j]));
			lst=tn;
		}
		adj[lst].pb(mp(y,b[1]));
		lst=y;
		for(int j=k;j>=2;j--){
			adj[lst].pb(mp(++tn,b[j]));
			lst=tn;
		}
		adj[lst].pb(mp(x,b[1]));
	}
	bfs();
	for(auto x:vec){
		for(int i=1;i<=19;i++) f[x][i]=f[f[x][i-1]][i-1];
		h1[x]=(h1[f[x][0]]*10+fp[x])%cys1;
		h2[x]=(h2[f[x][0]]*10+fp[x])%cys2;
		for(auto v:adj[x]){
			if(lev[x]+1!=lev[v.fi]) continue;
			if(!f[v.fi][0]){
				f[v.fi][0]=x,fp[v.fi]=v.se;
				continue;
			}
			int tmp=compare(x,f[v.fi][0]);
			if(tmp>0) f[v.fi][0]=x,fp[v.fi]=v.se;
			else if(tmp==0&&v.se<fp[v.fi]) f[v.fi][0]=x,fp[v.fi]=v.se;
		}
	}
	for(int i=2;i<=n;i++) printf("%lld\n",h1[i]);
	return 0;
}