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
int n,m,q,k;
int x[MN],y[MN],f[MN],g[MN];
vector<int>G[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",x+i,y+i);
	if(n&1)return puts("No"),0;
	F(i,1,n/2){
		int j=i+n/2,ok=0;
		if((x[i%n+1]-x[i])+(x[j%n+1]-x[j])==0&&(y[i%n+1]-y[i])+(y[j%n+1]-y[j])==0)ok=1;
		if(!ok)return puts("No"),0;
	}puts("Yes");
	return 0;
}