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
int v[600005],nxt[600005],h[300005],vis[300005];
vector<int> ans;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int t){
	if(t){
		vis[u]=1;
		ans.pb(u);
		vector<int> to(0);
		for(int p=h[u];p;p=nxt[p]){
			if(vis[v[p]]) continue;
			vis[v[p]]=2;
			to.pb(v[p]);
		}
		for(auto r:to) dfs(r,0);
	}
	else{
		for(int p=h[u];p;p=nxt[p]) if(!vis[v[p]]) dfs(v[p],1);
	}
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) h[i]=0; tot=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=m;i++) addedge(readint(),readint());
		ans.clear();
		dfs(1,1);
		bool fl=1;
		for(int i=1;i<=n;i++) if(!vis[i]) fl=0;
		if(!fl) printf("NO\n");
		else{
			printf("YES\n");
			printf("%d\n",ans.size());
			for(auto r:ans) printf("%d ",r);
			printf("\n");
		}
	}
	return 0;
}