#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,k,tot;
ll d[105][45],tmp[45],v[205],nxt[205],h[105];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	d[u][0]=d[u][k+1]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<=k+k;i++) for(int j=0;j<=k+k;j++) (tmp[i+j<=2*k?min(i,j+1):max(i,j+1)]+=d[u][i]*d[v[p]][j]%cys)%=cys;
		memcpy(d[u],tmp,sizeof(d[u]));
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dfs(1,-1);
	ll ans=0;
	for(int i=0;i<=k;i++) ans=(ans+d[1][i])%cys;
	cout<<ans<<endl;
	return 0;
}