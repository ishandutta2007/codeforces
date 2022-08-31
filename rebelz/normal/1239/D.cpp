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

int n,m,tot,cnt,scnt;
int dfn[2000005],low[2000005],col[2000005],v[4000005],nxt[4000005],h[2000005],x[2000005],y[2000005];
bool ins[2000005],vis[2000005];
stack<int> s;
vector<int> v1,v2;

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	s.push(u); ins[u]=true;
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]) tarjan(v[p]),low[u]=min(low[u],low[v[p]]);
		else if(ins[v[p]]) low[u]=min(low[u],dfn[v[p]]);
	}
	if(dfn[u]==low[u]){
		++scnt;
		do{
			col[u]=scnt;
			u=s.top(); s.pop(); ins[u]=false;
		}while(dfn[u]!=low[u]);
	}
}

bool getans(){
	for(int i=1;i<=n;i++) dfn[i]=low[i]=col[i]=ins[i]=0; scnt=cnt=0;
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	if(scnt==1) return false;
	v1.clear(); v2.clear();
	for(int i=1;i<=scnt;i++) vis[i]=0;
	for(int i=1;i<=m;i++) if(col[x[i]]!=col[y[i]]) vis[col[y[i]]]=1;
	for(int i=1;i<=scnt;i++){
		if(!vis[i]){
			for(int j=1;j<=n;j++){
				if(col[j]==i) v2.push_back(j);
				else v1.push_back(j);
			}
			return true;
		}
	}
	return false;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) h[i]=dfn[i]=low[i]=col[i]=0; tot=scnt=cnt=0;
		for(int i=1;i<=m;i++){
			x[i]=readint(); y[i]=readint();
			if(x[i]==y[i]) continue;
			addedge(x[i],y[i]);
		}
		if(n==1){
			printf("No\n");
			continue;
		}
		if(!getans()){
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		printf("%d %d\n",v1.size(),v2.size());
		for(auto x:v1) printf("%d ",x);
		printf("\n");
		for(auto x:v2) printf("%d ",x);
		printf("\n");
	}
	return 0;
}