#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	int a,b,n,n1;
	scanf("%d%d",&a,&b);
	n=a+b;
	n1=n/2;
	static int buk[MN];
	for(int i=0;i<=n;++i)buk[i]=0;
	for(int i1=0;i1<=a&&i1<=n1;++i1){
		int i2=n1-i1;
		int i3=a-i1;
		int i4=b-i2;
		if(i4>=0){
			buk[i1+i4]=buk[i2+i3]=1;
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i)ans+=buk[i];
	printf("%d\n",ans);
	for(int i=0;i<=n;++i)if(buk[i])printf("%d ",i);
	puts("");
}	return 0;
}