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
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,c[26];
char s[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%s",s+1),n=strlen(s+1);
	F2(i,0,26)c[i]=0;
	F(i,1,n)c[s[i]-'a']++;
	ll ans=*max_element(c,c+26);
	F2(a,0,26)F2(b,0,26){
		ll ss=0;int t=0;
		F(i,1,n){
			if(s[i]-'a'==b)ss+=t;
			if(s[i]-'a'==a)++t;
		}
//		if(ss)printf("%c%c ss=%lld\n",a+'a',b+'a',ss);
		ans=max(ans,ss);
	}
	printf("%lld\n",ans);
}	return 0;
}