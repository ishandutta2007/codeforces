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
int n,q;
int a[MN],p[MN],k[MN],x[MN],p2[MN],ans[MN];
int b[MN];
void add(int i){for(;i<=n;i+=i&-i)++b[i];}
int bs(int x){
	--x;int i=0;
	for(int j=18;j>=0;--j)
		if((i|1<<j)<=n&&b[i|1<<j]<=x)
			x-=b[i|=1<<j];
	return i+1;
}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),p[i]=i;
	sort(p+1,p+n+1,[](int i,int j){return a[i]==a[j]?i<j:a[i]>a[j];});
	scanf("%d",&q);
	F(i,1,q)scanf("%d%d",&k[i],&x[i]),p2[i]=i;
	sort(p2+1,p2+q+1,[](int i,int j){return k[i]<k[j];});
	int lst=0;
	F(id,1,q){
		int i=p2[id];
		int k=::k[i],x=::x[i];
		while(lst<k)add(p[++lst]);
		ans[i]=a[bs(x)];
	}
	F(i,1,q)printf("%d\n",ans[i]);
}	return 0;
}