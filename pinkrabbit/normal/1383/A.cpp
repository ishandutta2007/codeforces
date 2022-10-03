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
int n;
char a[MN],b[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%s%s",&n,a+1,b+1);
	int o=1;
	F(i,1,n)if(a[i]>b[i])o=0;
	if(!o){puts("-1");continue;}
	int ans=0;
	F(c,'a','t'-1){
		char mn='u';
		F(i,1,n)if(a[i]==c&&b[i]>c)mn=min(mn,b[i]);
		if(mn=='u')continue;
		++ans;
		F(i,1,n)if(a[i]==c&&b[i]>c)a[i]=mn;
	}
	printf("%d\n",ans);
}	return 0;
}