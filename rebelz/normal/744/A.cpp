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

int n,m,k,tot,ncnt,mcnt;
int a[100005],v[200005],nxt[200005],h[100005],col[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int c){
	ncnt++,col[u]=c;
	for(int p=h[u];p;p=nxt[p]){
		mcnt++;
		if(col[v[p]]) continue;
		dfs(v[p],c);
	}
}

int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=k;i++) a[i]=readint();
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	ll ans=0; int nmax=0;
	for(int i=1;i<=k;i++){
		ncnt=0,mcnt=0;
		dfs(a[i],i);
		mcnt/=2;
		ans+=1ll*ncnt*(ncnt-1)/2-mcnt;
		chkmax(nmax,ncnt);
	}
	for(int i=1;i<=n;i++){
		if(!col[i]){
			ncnt=0,mcnt=0;
			dfs(i,n+1);
			mcnt/=2;
			ans+=1ll*ncnt*nmax+1ll*ncnt*(ncnt-1)/2-mcnt;
			nmax+=ncnt;
		}
	}
	printf("%lld\n",ans);
	return 0;
}