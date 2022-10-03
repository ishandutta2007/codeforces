#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 105
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,a[MN][MN],b[MN][MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	vector<pair<int,pair<int,int>>>v;
	F(i,1,n)F(j,1,m)scanf("%d",&a[i][j]),b[i][j]=0,v.pb({a[i][j],{i,j}});
	sort(v.begin(),v.end());
	F(i,0,m-1)b[v[i].se.fi][v[i].se.se]=1;
//	F(i,1,n){F(j,1,m)printf("%d ",b[i][j]);puts("");}
	int p=0;
	F(i,1,n){
		vector<int>v1,v2;
		F(j,1,m)
			if(b[i][j])
				v1.pb(a[i][j]);
			else
				v2.pb(a[i][j]);
		int k=(int)v1.size();
		F(j,1,k)a[i][p+j]=v1[j-1];
		F(j,1,p)a[i][j]=v2[j-1];
		F(j,p+k+1,m)a[i][j]=v2[j-k-1];
		p+=k;
	}
	F(i,1,n){F(j,1,m)printf("%d ",a[i][j]);puts("");}
}	return 0;
}