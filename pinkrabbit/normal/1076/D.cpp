#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<LL,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int> st;

int n,q,m,k;
int S[300005],T[300005],W[300005];

int h[300005],nxt[600005],to[600005],w[600005],id[600005],tot;
inline void ins(int x,int y,int z,int zz){nxt[++tot]=h[x];to[tot]=y;w[tot]=z;id[tot]=zz;h[x]=tot;}

priority_queue<pii,vector<pii>,greater<pii> > pq;
LL dis[300005];
int fr[300005];
int cho[300005];

void dij(){
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	pq.push(pii(0ll,1));
	while(!pq.empty()){
		pii p=pq.top(); pq.pop();
		int u=p.second; LL d=p.first;
		if(d>dis[u]) continue;
		eF(i,u) if(dis[to[i]]>d+w[i]){
			dis[to[i]]=d+w[i];
			fr[to[i]]=id[i];
			pq.push(pii(dis[to[i]],to[i]));
		}
	}
}

int d[300005];
int que[300005],l=1,r;

int main(){
	int x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,m) scanf("%d%d%d",S+i,T+i,W+i), ins(S[i],T[i],W[i],i), ins(T[i],S[i],W[i],i);
	dij();
	F(i,2,n) cho[fr[i]]=1;
	F(i,2,n){
		int u=S[fr[i]], v=T[fr[i]];
		if(u==i) ++d[v];
		else ++d[u];
	}
	F(i,2,n) if(d[i]==0) que[++r]=i;
	k=max(0,n-1-k);
	while(l<=r){
		if(!k) break;
		int i=que[l++];
		int u=S[fr[i]], v=T[fr[i]];
		int j=(u==i?v:u);
		cho[fr[i]]=0;
		if(!(--d[j])) que[++r]=j;
		--k;
	}
	int Ans=0;
	F(i,1,m) if(cho[i]) ++Ans;
	printf("%d\n",Ans);
	F(i,1,m) if(cho[i]) printf("%d ",i);
	return 0;
}