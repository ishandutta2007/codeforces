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
int n,k;
int a[MN],b[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&k),printf("%d\n",n);
	F(i,1,n)scanf("%1d",a+i);
	F(i,1,n)b[i]=a[(i-1)%k+1];
	int ok=0;
	F(i,1,n)if(b[i]!=a[i]){if(b[i]<a[i])ok=1;break;}
	if(ok)++b[k];
	dF(i,k,1)if(b[i]==10)b[i]=0,++b[i-1];else break;
	F(i,1,n)printf("%d",b[(i-1)%k+1]);
}	return 0;
}