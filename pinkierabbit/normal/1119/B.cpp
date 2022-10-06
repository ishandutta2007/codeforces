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
const int Mod=998244353;
inline LL Pow(LL B,LL E,LL M=Mod){LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
#define INF 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f

map<int,int> mp;
set<int> st;

int n,q,m,k,h,ans;
int a[300005],b[300005];
int f[300005],g[300005];
int M[3005][3005];
char str[300005];


int main(){
	scanf("%d%d",&n,&h);
	F(i,1,n) scanf("%d",b+i);
	F(k,1,n){
		F(i,1,k)a[i]=b[i];
		sort(a+1,a+k+1);
		LL s=0;
		for(int i=k;i>=1;i-=2)s+=a[i];
		if(s<=h)ans=k;
	}printf("%d\n",ans);
	return 0;
}