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
int n,a[MN],b[MN],c[MN][2];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),b[i]=a[i];
	sort(b+1,b+n+1);
	F(x,1,100000)c[x][0]=c[x][1]=0;
	F(i,1,n)++c[a[i]][i&1];
	F(i,1,n)--c[b[i]][i&1];
	int ok=1;
	F(x,1,100000)if(c[x][0]||c[x][1]){ok=0;break;}
	puts(ok?"YES":"NO");
}	return 0;
}