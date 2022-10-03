#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 3005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m;
char s[MN],t[MN];
int f[MN][MN];
int ans;
int main(){
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	F(i,1,n)if(s[1]==t[i])f[i][i]=2;
	f[m+1][m]=2;
	ans=(ans+f[1][m])%mod;
	F(i,2,n){
//		printf("i=%d\n",i);
		char c=s[i];
		F(x,1,m-i+1){
			int y=x+i-1;
			f[x][y]=(f[x+1][y]*(t[x]==c)+f[x][y-1]*(t[y]==c))%mod;
//			printf("f[%d][%d] = %d\n",x,y,f[x][y]);
		}
		F(x,max(1,m-i+2),m){
			f[x][m]=(f[x+1][m]*(t[x]==c)+f[x][m])%mod;
//			printf("f[%d][%d] = %d\n",x,m,f[x][m]);
		}
		f[m+1][m]=2ll*f[m+1][m]%mod;
//			printf("f[%d][%d] = %d\n",m+1,m,f[m+1][m]);
//		 f[x][m] -> right : f[x][m]
		// left : f[x-1][m]
		ans=(ans+f[1][m])%mod;
	}
	printf("%d\n",ans);
	return 0;
}