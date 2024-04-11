#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,a[MN],f[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int ans=0;
	dF(i,n,1){
		if(i<n&&a[i]==a[i+1])++f[a[i]];
		else{
			int &v=f[a[i]]=0;
			for(int k=2*a[i];k<=200000;k+=a[i])v=max(v,f[k]);
			++v;
		}
		ans=max(ans,f[a[i]]);
	}
	printf("%d\n",n-ans);
	F(i,1,n)f[a[i]]=0;
}	return 0;
}