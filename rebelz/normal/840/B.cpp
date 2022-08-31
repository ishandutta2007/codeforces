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

int n,m,tot;
int a[300005],v[600005],c[600005],nxt[600005],h[300005];
bool vis[300005];
vector<int> ans;

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		vis[v[p]]=1;
		dfs(v[p]);
		if(a[v[p]]==1){
			ans.pb(c[p]);
			if(a[u]>=0) a[u]^=1;
			a[v[p]]^=1;
		}
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) addedge(readint(),readint(),i);
	int rt=0,tmp=0;
	for(int i=1;i<=n;i++){
		if(a[i]<0) rt=i;
		else tmp^=a[i];
	}
	if(!rt&&(tmp&1)) return printf("-1\n"),0;
	if(!rt) rt=1;
	vis[rt]=1; dfs(rt);
	printf("%d\n",ans.size());
	for(auto r:ans) printf("%d ",r);
	printf("\n");
	return 0;
}