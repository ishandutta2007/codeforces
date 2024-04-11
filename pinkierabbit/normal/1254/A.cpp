#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 105
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
int n,m,k,v;
char a[MN][MN],A[MN][MN];
int xx(int i){return (i-1)/m+1;}
int yy(int i){return !((i-1)/m%2)?(i-1)%m+1:m-(i-1)%m;}
char bet(int i){return i<10?'0'+i:i-10<26?'A'+i-10:'a'+i-10-26;}
int main(){int t;scanf("%d",&t);while(t--){
	scanf("%d%d%d",&n,&m,&k),v=0;
	F(i,1,n)scanf("%s",a[i]+1);
	F(i,1,n*m)if(a[xx(i)][yy(i)]=='R')++v;
//	F(i,1,n*m)printf("%d,%d\n",xx(i),yy(i));
	int c=v/k,d=v%k,e=0,f=0;
	F(i,1,n*m){
		A[xx(i)][yy(i)]=bet(e);
		if(a[xx(i)][yy(i)]=='R')++f;
		if((e<d&&f==c+1)||(e>=d&&f==c))++e,f=0;
		if(e>=k)--e;
	}
	F(i,1,n)A[i][m+1]=0;
	F(i,1,n)printf("%s\n",A[i]+1);
}return 0;}