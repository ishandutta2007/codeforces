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

int n,m,ncnt,scnt,tot;
int dfn[200005],low[200005],col[200005],v[200005],nxt[200005],h[200005];
bool ins[200005];
vector<int> a[100005];
stack<int> s;

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void tarjan(int u){
	dfn[u]=low[u]=++ncnt;
	s.push(u); ins[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]) tarjan(v[p]),chkmin(low[u],low[v[p]]);
		else if(ins[v[p]]) chkmin(low[u],dfn[v[p]]);
	}
	if(dfn[u]==low[u]){
		scnt++;
		int tmp;
		do{
			tmp=s.top(); s.pop();
			col[tmp]=scnt,ins[tmp]=0;
		}while(tmp!=u);
	}
}

int main(){
	n=readint(); m=readint();
	int x;
	for(int i=1;i<=n;i++){
		x=readint();
		for(int j=1;j<=x;j++) a[i].pb(readint());
	}
	for(int i=1;i<n;i++){
		int tmp=min(a[i].size(),a[i+1].size());
		bool fl=0;
		for(int j=0;j<tmp;j++){
			if(a[i][j]!=a[i+1][j]){
				if(a[i][j]<a[i+1][j]) addedge(a[i+1][j]+m,a[i][j]+m),addedge(a[i][j],a[i+1][j]);
				else addedge(a[i][j],a[i][j]+m),addedge(a[i+1][j]+m,a[i+1][j]);
				fl=1;
				break;
			}
		}
		if(!fl&&a[i].size()>a[i+1].size()) return printf("No\n"),0;
	}
	for(int i=1;i<=m+m;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=m;i++) if(col[i]==col[i+m]) return printf("No\n"),0;
	vector<int> ans(0);
	for(int i=1;i<=m;i++) if(col[i]>col[i+m]) ans.pb(i);
	printf("Yes\n");
	printf("%d\n",ans.size());
	for(auto r:ans) printf("%d ",r);
	printf("\n");
	return 0;
}