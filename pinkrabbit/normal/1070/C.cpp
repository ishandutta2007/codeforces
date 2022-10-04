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
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int,int> st;

int n,k,m;
int l[200005],r[200005],c[200005],p[200005];

int h[1000005],nxt[400005],to[400005],w[400005],tot;
inline void ins(int x,int y,int z){nxt[++tot]=h[x];to[tot]=y;w[tot]=z;h[x]=tot;}

LL b1[1000005],b2[1000005];
void A(LL*b, int i, LL x){for(;i<=1000000;i+=i&-i)b[i]+=x;}
LL Q(LL*b,int i){LL A=0;for(;i;i-=i&-i)A+=b[i];return A;}
int LB(LL X){
	LL Sum=0, pos=0, j=1<<19;
	while(j){
		if(Sum+b1[pos+j]<X) pos+=j, Sum+=b1[pos];
		j>>=1;
	} return pos;
}
LL Ans;

int main(){
	scanf("%d%d%d",&n,&k,&m);
	F(i,1,m) scanf("%d%d%d%d",l+i,r+i,c+i,p+i), ins(l[i],p[i],c[i]), ins(r[i]+1,p[i],-c[i]);
	F(i,1,n){
		eF(j,i) A(b1,to[j],w[j]), A(b2,to[j],(LL)to[j]*w[j]);
		if(Q(b1,1000000)<k) Ans+=Q(b2,1000000);
		else{
			int pos=LB(k);
			Ans+=Q(b2,pos);
			Ans+=(LL)(pos+1)*(k-Q(b1,pos));
		}
	} printf("%lld\n",Ans);
	return 0;
}