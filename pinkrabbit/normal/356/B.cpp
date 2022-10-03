#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
ll n,m,k,ans;
int a,b,c;
char s[MN],t[MN];
int buk[26];
int main(){
	scanf("%lld%lld%s%s",&n,&m,s+1,t+1);
	a=strlen(s+1),b=strlen(t+1);
	c=__gcd(a,b);
	k=n/(b/c);
//	printf("k=%lld\n",k);
	F(z,1,c){
		F2(k,0,26)buk[k]=0;
//		F2(i,0,a/c)printf("%c",s[i*c+z]);puts("");
//		F2(j,0,b/c)printf("%c",t[j*c+z]);puts("");
		int cnt=0;
		F2(i,0,a/c)++buk[s[i*c+z]-'a'],++cnt;
		F2(j,0,b/c)ans+=cnt-buk[t[j*c+z]-'a'];
	}
	printf("%lld\n",ans*k);
	return 0;
}