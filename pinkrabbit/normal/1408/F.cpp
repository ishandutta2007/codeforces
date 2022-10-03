#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
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
pii a[MN];int q;
void d(int b,int l){
	for(int j=1;j<l;j*=2)
		for(int i=1;i<=l;i+=2*j)
			for(int o=0;o<j;++o)
				a[++q]={b+i+o,b+i+j+o};
}
int main(){
	scanf("%d",&n);
	if(n<=2)return puts("0"),0;
	int k=1;
	while(2*k<=n)k*=2;
	if(k==n)d(0,n/2),d(n/2,n/2);
	else d(0,k),d(n-k,k);
	printf("%d\n",q);
	F(i,1,q)printf("%d %d\n",a[i].fi,a[i].se);
	return 0;
}