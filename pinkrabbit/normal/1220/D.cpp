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
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n;
ll a[MN];
int b[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%lld",a+i),++b[__builtin_ctzll(a[i])];
//	F(j,0,61)printf("%d ",b[j]);
	int z=max_element(b,b+62)-b;
	printf("%d\n",n-b[z]);
	F(i,1,n)if(__builtin_ctzll(a[i])!=z)printf("%lld ",a[i]);
	return 0;
}