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
int n;char s[MN];int a[MN],b[MN],c[MN],d;
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%s",&n,s+1);
	F(i,1,n)a[i]=s[i]=='B';
	{
		F(i,1,n)b[i]=a[i],c[i]=0;d=0;
		F(i,1,n-1)if(b[i])b[i]^=1,b[i+1]^=1,c[i]=1,++d;
		if(!b[n]){
			printf("%d\n",d);
			F(i,1,n-1)if(c[i])printf("%d ",i);
			return 0;
		}
	}
	{
		F(i,1,n)b[i]=a[i],c[i]=0;d=0;
		F(i,1,n-1)if(!b[i])b[i]^=1,b[i+1]^=1,c[i]=1,++d;
		if(b[n]){
			printf("%d\n",d);
			F(i,1,n-1)if(c[i])printf("%d ",i);
			return 0;
		}
	}
	puts("-1");
}	return 0;
}