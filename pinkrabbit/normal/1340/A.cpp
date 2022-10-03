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
int a[MN],b[MN],v[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),b[a[i]]=i,v[i]=0;
	int ok=1,m=n+1;
	F(i,1,n)if(!v[i]){
		int p=b[i];
		F2(j,p,m)if(a[j]!=i+j-p)ok=0;
		if(!ok)break;
		F2(j,p,m)v[a[j]]=1;
		m=p;
	}
	puts(ok?"Yes":"No");
}	return 0;
}