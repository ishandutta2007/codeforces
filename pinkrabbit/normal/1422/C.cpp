#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int len,a[MN];
char s[MN];
int main(){
	scanf("%s",s+1),len=strlen(s+1);
	F(i,1,len)a[i]=s[i]-'0';
	int ans=0,sum=0;
	dF(i,len,1){
		sum=(sum+(ll)a[i]*qpow(10,len-i))%mod;
		ans=(ans+(ll)(i-1)*sum)%mod;
	}
	sum=0;
	int inv9=qpow(9,mod-2);
	F(i,1,len){
		sum=(10ll*sum+a[i])%mod;
		ans=(ans+sum*((ll)(qpow(10,len-i)-1)*inv9%mod))%mod;
	}
	printf("%d\n",ans);
	return 0;
}