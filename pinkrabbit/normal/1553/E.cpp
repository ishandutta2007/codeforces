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
int n,m,a[MN],b[MN],ia[MN],f[MN],v[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F2(i,0,n)b[i]=0;
	F(i,1,n)scanf("%d",a+i),++b[(i-a[i]+n)%n],ia[a[i]]=i;
//	F2(i,0,n)printf("%d,",b[i]);puts("");
	int d=n-n/3*2;
//	printf("d=%d\n",d);
	vector<int>ans;
	F2(j,0,n)if(b[j]>=d){
		F(i,1,n)
			f[i]=ia[(i-j+n-1)%n+1];
//		printf("j=%d:\n",j);
//		F(i,1,n)printf("%d%c",f[i]," \n"[i==n]);
		F(i,1,n)v[i]=0;
		int cnt=n;
		F(i,1,n)if(!v[i]){
			--cnt;
			v[i]=1;
			for(int x=f[i];x!=i;x=f[x])
				v[x]=1;
		}
		if(cnt<=m)ans.pb(j);
	}
	printf("%d",(int)ans.size());
	for(int x:ans)printf(" %d",x);
	puts("");
}	return 0;
}