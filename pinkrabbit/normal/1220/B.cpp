#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,g;
ll a[MN][MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)F(j,1,n)scanf("%lld",&a[i][j]);
	F(i,1,n)a[i][i]=(ll)a[i][(i+1)%n+1]*a[i%n+1][i]/a[i%n+1][(i+1)%n+1];
//	F(i,1,n)F(j,1,n)printf("%lld%c",a[i][j]," \n"[j==n]);
	F(i,1,n){
		ll x=sqrt(a[i][i]);
		while((x+1)*(x+1)<=a[i][i])++x;
		while(x*x>a[i][i])--x;
		printf("%lld ",x);
	}
	return 0;
}