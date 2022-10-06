#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 2005
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
int n,k;char s[MN],t[MN];
int main(){int tests;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%s",&n,&k,s+1);
	F(i,1,k-1)t[i*2-1]='(',t[i*2]=')';
	F(i,1,n/2-k+1)t[2*k-2+i]='(',t[n-i+1]=')';
	t[n+1]=0;
//	printf("%s\n",t+1);
	printf("%d\n",n);
	dF(x,n,1){
		int p=0;
		F(i,1,x)if(s[i]==t[x])p=i;
		printf("%d %d\n",p,x);
		reverse(s+p,s+x+1);
	}
//	printf("%s\n",s+1);
}	return 0;
}