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
int n,m,q,k;
char s[MN],t[MN];
char ss[MN],tt[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%s%s",&n,s+1,t+1);
	F(i,1,n)ss[i]=s[i],tt[i]=t[i];
	sort(ss+1,ss+n+1),sort(tt+1,tt+n+1);
	int ok=1;
	F(i,1,n)if(ss[i]!=tt[i])ok=0;
	if(!ok){puts("-1");continue;}
	int ans=0;
	F(i,1,n){
		int k=1;
		F(j,i,n){
			while(k<=n&&s[k]!=t[j])++k;
			if(k<=n)ans=max(ans,j-i+1),++k;
			else break;
		}
	}
	printf("%d\n",n-ans);
}	return 0;
}