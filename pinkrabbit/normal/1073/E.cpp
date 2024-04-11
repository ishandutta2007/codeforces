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
#define mod 998244353
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
const int INF=0x3f3f3f3f;

int k;

int fu(LL x){
	if(x<=9) return x*(x+1)/2;
	int num[20],len=0;
	while(x) num[++len]=x%10, x/=10;
	int S=0;
	LL Sum=0;
	int f[20][1<<10],g[20][1<<10]; memset(f,0,sizeof f);memset(g,0,sizeof g);
	//===
	F(i,1,num[len]-1){
		f[len][1<<i]=1;
		g[len][1<<i]=i;
	}
	S=(1<<num[len]); Sum=num[len];
	//===
	dF(i,len-1,1){
		F2(A,0,1<<10){
			F(j,0,9){
				f[i][A|(1<<j)]+=f[i+1][A];
				f[i][A|(1<<j)]%=mod;
				g[i][A|(1<<j)]+=(g[i+1][A]*10ll%mod+(LL)f[i+1][A]*j%mod)%mod;
				g[i][A|(1<<j)]%=mod;
			}
		}
		F(j,0,num[i]-1){
			++f[i][S|(1<<j)];
			f[i][S|(1<<j)]%=mod;
			g[i][S|(1<<j)]+=(Sum*10ll%mod+j)%mod;
			g[i][S|(1<<j)]%=mod;
		}
		F(j,1,9){
			++f[i][1<<j];
			f[i][1<<j]%=mod;
			g[i][1<<j]+=j;
			g[i][1<<j]%=mod;
		}
		S|=(1<<num[i]); Sum=(Sum*10ll+num[i])%mod;
	}
	LL Ans=0;
	F2(A,0,1<<10) if(__builtin_popcount(A)<=k){
		Ans+=g[1][A];
		Ans%=mod;
	} return (Ans+(__builtin_popcount(S)<=k?Sum:0))%mod;
}

int main(){
	LL LB,RB;
	scanf("%lld%lld%d",&LB,&RB,&k);
	printf("%d\n",(fu(RB)-fu(LB-1)+mod)%mod);
	return 0;
}
// 1 100 10