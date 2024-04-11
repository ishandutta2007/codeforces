#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,a,b,w[77][77],id[18],cnt,tmp,f[20000000],q1[20000000],q2[20000000],h1,r1,h2,r2;
bool vis1[77],vis2[77];
int dfs1(int u){
	vis1[u]=true;
	int s=1;
	FOR(i,1,n) if(w[u][i]==a && !vis1[i]) s+=dfs1(i);
	return s;
}
void dfs2(int u,int c){
	vis2[u]=true;
	id[u]=c;
	FOR(i,1,n) if(w[u][i]==a && !vis2[i]) dfs2(i,c);
}
inline int at(int x,int y){return x*n+y-1;}
int main(){
	n=read();m=read();a=read();b=read();
	FOR(i,1,m){
		int u=read(),v=read();
		w[u][v]=w[v][u]=read();
	}
	FOR(i,1,n) if(!vis1[i]) if(dfs1(i)>=4) dfs2(i,++cnt);
	tmp=cnt;
	MEM(vis1,0);
	FOR(i,1,n) if(!vis1[i]) if(dfs1(i)<4) dfs2(i,++cnt);
	MEM(f,0x7f);
	f[at(0,1)]=0;
	q1[h1=r1=1]=at(0,1);q2[h2=r2=1]=at(0,1);
	while(h1<=r1 || h2<=r2){
		int u;
		if(h1>r1) u=q2[h2++];
		else if(h2>r2) u=q1[h1++];
		else if(f[q1[h1]]<f[q2[h2]]) u=q1[h1++];
		else u=q2[h2++];
		int x=u/n,y=u%n+1;
		FOR(i,1,n){
			if(!w[y][i] || (id[i]<=tmp && (x&(1<<(id[i]-1)))) || (id[i]==id[y] && w[y][i]==b)) continue;
			int v;
			if(id[y]<=tmp && id[y]!=id[i]) v=at(x|(1<<(id[y]-1)),i);
			else v=at(x,i);
			if(f[v]>f[u]+w[y][i]){
				f[v]=f[u]+w[y][i];
				if(w[y][i]==a) q1[++r1]=v;
				else q2[++r2]=v;
			}
		}
	}
	FOR(i,1,n){
		int ans=2e9;
		FOR(j,0,(1<<tmp)-1) ans=min(ans,f[at(j,i)]);
		printf("%d ",ans);
	}
}