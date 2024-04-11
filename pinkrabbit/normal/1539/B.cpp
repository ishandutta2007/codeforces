#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 100005
#define MM 26
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
int n,m,q,k;
char str[MN];
int s[26][MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&q);
	scanf("%s",str+1);
	F(i,1,n){
		F2(j,0,MM)
			s[j][i]=s[j][i-1];
		++s[str[i]-'a'][i];
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int num=0;
		F2(j,0,MM)
			num+=(s[j][r]-s[j][l-1])*(j+1);
		printf("%d\n",num);
	}
}	return 0;
}