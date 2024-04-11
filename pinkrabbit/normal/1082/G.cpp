#include<cstdio> 
#define F(i,a) for(int i=1;i<=a;++i) 
#define eF(i,s) for(int i=h[s];i;i=nxt[i]) 
long long Min(long long p,long long q){return p<q?p:q;} 
const long long INF=1e16;
int n,m;
int h[10001],to[200002],nxt[200002],t=1;
long long cap[200002];
void ins(int x,int y,long long c){to[++t]=y;cap[t]=c;nxt[t]=h[x];h[x]=t;to[++t]=x;cap[t]=0;nxt[t]=h[y];h[y]=t;}
int lv[10001],q[10001],l,r;
void lvl(int s){
	l=1;r=0;
	q[++r]=s;lv[s]=1;
	while(l<=r){
		int u=q[l++];
		eF(i,u){
			if(!lv[to[i]]&&cap[i]){
				lv[to[i]]=lv[u]+1;
				q[++r]=to[i];
			}
		}
	}
}
long long flow(int u,int t,long long f){
	if(u==t)return f;
	long long ans=0;
	eF(i,u){
		if(lv[to[i]]==lv[u]+1&&cap[i]){
			long long d=flow(to[i],t,Min(f,cap[i]));
			ans+=d;
			f-=d;
			cap[i]-=d;cap[i^1]+=d;
		}
	}
	return ans;
}
long long Dinic(int S,int T){
	long long ans=0;
	while(1){
		F(i,n)lv[i]=0;
		lvl(S);
		if(!lv[T])break;
		ans+=flow(S,T,INF);
	}
	return ans;
}
int main(){
	int N,M,x,y,z;
	long long Sum=0;
	scanf("%d%d",&N,&M); n=N+2;
	F(i,N) scanf("%d",&x), ins(1,i+2,x);
	F(i,M) scanf("%d%d%d",&x,&y,&z), ++n, ins(x+2,n,INF), ins(y+2,n,INF), ins(n,2,z), Sum+=z;
	printf("%lld\n",Sum-Dinic(1,2));
	return 0;
}