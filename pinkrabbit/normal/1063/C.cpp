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

int n,q,m;
int a[300001],b[300001];
int f[300001],g[300001];
int M[3005][3005];

int print(int x,int y){
	printf("%d %d\n",x,y);
	fflush(stdout);
	char str[9];
	scanf("%s",str);
	return *str=='b';
}

int main(){
	scanf("%d",&n);
	int C=print(1,1);
	if(n==1) prts("2 0 2 1");
	int D=print(999999999,1);
	if(n==2){
		if(C==D) prts("0 2 1 2");
		else prts("2 0 2 1");
	}
	if(C!=D){
		n-=2;
		int l=1, r=999999999;
		while(n--){
			int mid=l+r>>1;
			int E=print(mid,1);
			if(E==C) l=mid;
			else r=mid;
		}
		printf("%d %d %d %d\n",l,2,r,0);
		return 0;
	}
	else{
		int E=print(1,999999999);
		if(n==3){
			if(E==C) prts("0 1000000000 1 1000000000");
			else prts("0 2 1 2");
		}
		if(E!=C){
			n-=3;
			int l=1, r=999999999;
			while(n--){
				int mid=l+r>>1;
				int E=print(1,mid);
				if(E==C) l=mid;
				else r=mid;
			}
			printf("%d %d %d %d\n",0,l,2,r);
			return 0;
		}
		else{
			n-=3;
			int l=1, r=999999999;
			while(n--){
				int mid=l+r>>1;
				int E=print(999999999,mid);
				if(E==C) l=mid;
				else r=mid;
			}
			if(1000000000-r>l) r+=l, l=0;
			else l-=1000000000-r, r=1000000000;
			printf("%d %d %d %d\n",999999998,r,1000000000,l);
			return 0;
		}
	}
	return 0;
}