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
char s[MN],t[MN];
int n,m;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	int j=m;
	dF(i,n,1){
		if(((m-j)+(n-i))&1)continue;
		if(s[i]==t[j])--j;
		if(!j)break;
	}
	puts(j?"NO":"YES");
}	return 0;
}