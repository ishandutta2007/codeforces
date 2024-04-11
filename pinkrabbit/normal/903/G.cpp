#include<bits/stdc++.h>
using namespace std;
#define LL long long
int N,M,Q;
int A[200005],B[200005];
int h[200005],nxt[200005],to[200005],w[200005],tot;
inline void ins(int x,int y,int z){nxt[++tot]=h[x];to[tot]=y;w[tot]=z;h[x]=tot;}
LL g[200005];
LL mn[1<<19],tg[1<<19];
void P(int i,LL x){mn[i]+=x;tg[i]+=x;}
void pd(int i){P(i<<1,tg[i]);P(i<<1|1,tg[i]);tg[i]=0;}
void Add(int i,int l,int r,int a,int b,LL x){
	if(r<a||b<l) return;
	if(a<=l&&r<=b){P(i,x); return;}
	pd(i);Add(i<<1,l,l+r>>1,a,b,x),Add(i<<1|1,(l+r>>1)+1,r,a,b,x);
	mn[i]=min(mn[i<<1],mn[i<<1|1]);
}
int main(){
	int x,y,z;
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=1;i<N;++i) scanf("%d%d",A+i,B+i);
	for(int i=1;i<=M;++i) scanf("%d%d%d",&x,&y,&z), ins(x,y,z);
	for(int i=1;i<N;++i) Add(1,1,N,i+1,i+1,B[i]);
	for(int i=1;i<=N;++i){
		for(int j=h[i];j;j=nxt[j])
			Add(1,1,N,1,to[j],w[j]);
		g[i]=mn[1];
	}
	memset(mn,0,sizeof mn), memset(tg,0,sizeof tg);
	for(int i=1;i<=N;++i) Add(1,1,N,i,i,A[i]+g[i]);
	printf("%lld\n",mn[1]);
	for(int i=1;i<=Q;++i){
		scanf("%d%d",&x,&y);
		Add(1,1,N,x,x,y-A[x]);
		A[x]=y;
		printf("%lld\n",mn[1]);
	}
	return 0;
}