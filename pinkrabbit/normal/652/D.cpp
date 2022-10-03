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
int x[MN],y[MN],p[MN],ans[MN];
int b[MN];
int B[MN];
void add(int i){for(;i<=n;i+=i&-i)++B[i];}
int qur(int i){int a=0;for(;i;i-=i&-i)a+=B[i];return a;}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",x+i,y+i),p[i]=i;
	sort(p+1,p+n+1,[](int i,int j){return x[i]>x[j];});
	F(i,1,n)b[i]=y[i];
	sort(b+1,b+n+1);
	F(i,1,n)y[i]=lower_bound(b+1,b+n+1,y[i])-b;
	F(I,1,n){
		int i=p[I];
		ans[i]=qur(y[i]);
		add(y[i]);
	}
	F(i,1,n)printf("%d\n",ans[i]);
	return 0;
}