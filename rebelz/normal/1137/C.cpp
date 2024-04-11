#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
 
map<int,bool> mp;
stack<int> st;
int n,m,k,tot,cnt;
int v[5000005],nxt[5000005],h[5000005],d[5000005],dfn[5000005],low[5000005],b[5000005],du[5000005],q[5000005],x[100005],y[100005];
char s[55];
bool vis[5000005],f[5000005];
 
void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}
int id(int x,int y){return (x-1)*k+y;}
 
inline void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	st.push(u); vis[u]=true;
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]){
			tarjan(v[p]);
			low[u]=min(low[u],low[v[p]]);
		}
		else if(vis[v[p]]) low[u]=min(low[u],dfn[v[p]]);
	}
	if(dfn[u]==low[u]){
		while(int t=st.top()){
			vis[t]=false; st.pop();
			b[t]=u;
			if(f[t]) mp[(t-1)/k+1]=1;
			if(t==u) break;
		}
		for(auto x:mp) d[u]+=x.second;
		mp.clear();
	}
}
 
void toposort(){
	for(int i=1;i<=m;i++) for(int j=1;j<=k;j++) if(b[id(x[i],j)]!=b[id(y[i],j%k+1)]) addedge(b[id(x[i],j)],b[id(y[i],j%k+1)]),du[b[id(y[i],j%k+1)]]++;
	int front=1,rear=1;
	for(int i=1;i<=id(n,k);i++) if(b[i]==i&&du[i]==0) q[rear++]=i;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]) if(!(--du[v[p]])) q[rear++]=v[p];
	}
	for(int i=rear-1;i>=1;i--){
		int tmp=0;
		for(int p=h[q[i]];p;p=nxt[p]) tmp=max(tmp,d[v[p]]);
		d[q[i]]+=tmp;
	}
}
 
int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=m;i++){
		x[i]=readint(); y[i]=readint();
		for(int j=1;j<=k;j++) addedge(id(x[i],j),id(y[i],j%k+1));
	}
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=k;j++) if(s[j]=='1') f[id(i,j)]=1;
	}
	for(int i=1;i<=id(n,k);i++) if(!dfn[i]) tarjan(i);
//	for(int i=1;i<=id(n,k);i++) cout<<b[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=id(n,k);i++) cout<<d[b[i]]<<' ';
//	cout<<endl;
	memset(h,0,sizeof(h)); tot=0;
	toposort();
//	for(int i=1;i<=id(n,k);i++) cout<<d[b[i]]<<' ';
//	cout<<endl;
	printf("%d\n",d[b[id(1,1)]]);
	return 0;
}