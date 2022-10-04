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
set<int> st;

LL n,m;
LL X1,Y1,X2,Y2;
LL X3,Y3,X4,Y4;
LL chkw(LL X1,LL Y1,LL X2,LL Y2);

LL chkb(LL X1,LL Y1,LL X2,LL Y2){
	if(X1==1&&Y1==1) return X2*Y2/2;
	if((X1&1)^(Y1&1)) return chkw(1,1,X2-X1+1,Y2-Y1+1);
	else return chkb(1,1,X2-X1+1,Y2-Y1+1);
}
LL chkw(LL X1,LL Y1,LL X2,LL Y2){
	return (X2-X1+1)*(Y2-Y1+1)-chkb(X1,Y1,X2,Y2);
}

int main(){
	int Te;
	scanf("%d",&Te);
	while(Te--){
		scanf("%lld%lld",&n,&m);
		swap(n,m);
		scanf("%lld%lld%lld%lld",&X1,&Y1,&X2,&Y2);
		scanf("%lld%lld%lld%lld",&X3,&Y3,&X4,&Y4);
		LL Ans1, Ans2=n*m/2; Ans1=n*m-Ans2;
		// ans1  ans2 
		Ans2+=chkw(X3,Y3,X4,Y4);
		Ans1-=chkw(X3,Y3,X4,Y4);
		Ans1+=chkb(X1,Y1,X2,Y2);
		Ans2-=chkb(X1,Y1,X2,Y2);
		if(max(X1,X3)<=min(X2,X4)&&max(Y1,Y3)<=min(Y2,Y4)){
			Ans2+=chkb(max(X1,X3),max(Y1,Y3),min(X2,X4),min(Y2,Y4));
			Ans1-=chkb(max(X1,X3),max(Y1,Y3),min(X2,X4),min(Y2,Y4));
		}
		printf("%lld %lld\n",Ans1,Ans2);
	}
	return 0;
}