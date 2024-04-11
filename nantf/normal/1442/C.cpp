#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
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
int n,m,el,head[maxn],to[maxn],nxt[maxn],w[maxn];
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
int d[maxn][21][2],h=1,r,q[maxn*42];
inline int id(int x,int y,int z){
	return x*42+y*2+z;
}
int work1(){
	MEM(d,0x3f);
	d[1][0][0]=0;
	q[++r]=id(1,0,0);
	while(h<=r){
		int u=q[h++];
		int x=u/42,y=u/2%21,z=u%2;
		for(int i=head[x];i;i=nxt[i]){
			int tx=to[i],ty=y+(w[i]!=z),tz=w[i];
			if(ty<=20 && d[tx][ty][tz]>d[x][y][z]+1){
				d[tx][ty][tz]=d[x][y][z]+1;
				q[++r]=id(tx,ty,tz);
			}
		}
	}
	int ans=1.1e9;
	FOR(i,0,20) FOR(j,0,1) ans=min(ans,d[n][i][j]+(1<<i)-1);
	return ans;
}
PII dis[maxn][2];
struct node{
	PII u,d;
	bool operator<(const node &nd)const{return d>nd.d;}
};
priority_queue<node> pq;
PII work2(){
	MEM(dis,0x3f);
	dis[1][0]=MP(0,0);
	pq.push((node){MP(1,0),MP(0,0)});
	while(!pq.empty()){
		node nd=pq.top();pq.pop();
		int x=nd.u.first,y=nd.u.second;
		if(nd.d>dis[x][y]) continue;
		for(int i=head[x];i;i=nxt[i]){
			int tx=to[i],ty=w[i];
			PII tmp=dis[x][y];
			tmp.first+=y!=w[i];
			tmp.second++;
			if(dis[tx][ty]>tmp){
				dis[tx][ty]=tmp;
				pq.push((node){MP(tx,ty),tmp});
			}
		}
	}
	return min(dis[n][0],dis[n][1]);
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v,0);add(v,u,1);
	}
	int ans1=work1();
	PII ans2=work2();
	if(ans1<1e9){
		if(ans2.first>20) printf("%d\n",ans1);
		else printf("%d\n",min(ans1,qpow(2,ans2.first)-1+ans2.second));
	}
	else printf("%d\n",(qpow(2,ans2.first)-1+ans2.second)%mod);
}