#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 400005
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;
int a[MN],b[MN],c[MN],d[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)scanf("%d",b+i);
	F(i,1,n)c[a[i]]=i,d[i]=0;
	int ans=1;
	F(i,1,n)if(!d[i]){
		int x=i;
		do{
			x=c[b[x]];
			d[x]=1;
		}while(x!=i);
		ans=2*ans%mod;
	}
	printf("%d\n",ans);
}	return 0;
}