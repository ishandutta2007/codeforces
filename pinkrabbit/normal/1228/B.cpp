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
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
int a[MN],b[MN];
int c[MN][MN];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,m)scanf("%d",b+i);
	F(i,1,n)F(j,1,a[i]+1)c[i][j]+=j<=a[i]?1:2;
	F(i,1,m)F(j,1,b[i]+1)c[j][i]+=j<=b[i]?3:6;
	int d=1;
//	F(i,1,n)F(j,1,m)printf("%d%d%c",c[i][j]/3,c[i][j]%3," \n"[j==m]);
	F(i,1,n)F(j,1,m){int x=c[i][j];if(!(x%3)&&!(x/3))d=d*2ll%mod;else if(!(x%3)||!(x/3));else if(x%3!=x/3)d=0;else;}
	printf("%d\n",d);
	return 0;
}