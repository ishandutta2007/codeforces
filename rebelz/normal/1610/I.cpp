// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot,cnt,ans;
int v[600005],nxt[600005],h[300005],f[300005],d[300005];
bool tag[300005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]]=u;
		dfs(v[p],u);
		d[u]^=d[v[p]]+1;
	}
}

void update(int u){
	cnt^=1;
	if(!tag[f[u]]) update(f[u]);
	ans^=d[f[u]];
	d[f[u]]^=d[u]+1;
	ans^=d[f[u]];
	tag[u]=1;
	ans^=d[u];
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs(1,-1);
	ans=d[1];
	putchar(ans?'1':'2');
	tag[1]=1;
	for(int i=2;i<=n;i++){
		if(!tag[i]) update(i);
		putchar((ans^cnt)?'1':'2');
	}
	putchar('\n');
	return 0;
}