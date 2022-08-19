#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot,s,ncnt,bcc; ll res=0,now=0;
int v[400005],nxt[400005],h[200005],dfn[200005],low[200005],col[200005],x[200005],y[200005],siz[200005];
ll val[200005],a[200005],ans[200005];
bool ins[200005];
stack<int> ss;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void tarjan(int u,int fa){
	dfn[u]=low[u]=++ncnt;
	ss.push(u);
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]){
			tarjan(v[p],u);
			low[u]=min(low[u],low[v[p]]);
			if(low[v[p]]>dfn[u]){
				bcc++;
				while(ss.top()!=v[p]) col[ss.top()]=bcc,val[bcc]+=a[ss.top()],ss.pop(),siz[bcc]++;
				col[v[p]]=bcc,val[bcc]+=a[v[p]],ss.pop(),siz[bcc]++;
			}
		}
		else if(v[p]!=fa) low[u]=min(low[u],dfn[v[p]]);
	}
}

bool dfs(int u){
	ll all=0; bool cm=true;
	if(siz[u]==1) cm=false;
	for(int p=h[u];p;p=nxt[p]){
		if(ins[v[p]]) continue;
		ins[v[p]]=true;
		if(dfs(v[p])) cm=true;
		all=max(all,ans[v[p]]);
	}
	ans[u]=all+val[u];
//	cout<<"test "<<u<<' '<<cm<<' '<<val[u]<<endl;
	if(cm) res+=val[u];
	else now=max(now,ans[u]);
	return cm;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++){
		x[i]=readint(); y[i]=readint();
		addedge(x[i],y[i]);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i,-1);
			bcc++;
			while(!ss.empty()) col[ss.top()]=bcc,ins[ss.top()]=false,val[bcc]+=a[ss.top()],ss.pop(),siz[bcc]++;
		}
	}
//	for(int i=1;i<=n;i++) cout<<col[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=bcc;i++) cout<<val[i]<<' ';
//	cout<<endl;
	memset(h,0,sizeof(h)); tot=0;
	for(int i=1;i<=m;i++) if(col[x[i]]!=col[y[i]]) addedge(col[x[i]],col[y[i]]);
	s=readint(); ins[col[s]]=true;
	dfs(col[s]);
	printf("%lld\n",res+now);
	return 0;
}