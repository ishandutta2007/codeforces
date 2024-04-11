#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define ML 1005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,l,k;
char s[MN*ML];
char a[MN][ML];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d%s",&n,&l,&k,s+1);
	sort(s+1,s+n*l+1);
	int p=0,t=0;
	F(j,1,l){
		F(i,1,k)a[p+i][j]=s[++t];
		while(a[p+1][j]!=a[p+k][j])++p,--k;
	}
	F(i,1,n)F(j,1,l)if(!a[i][j])a[i][j]=s[++t];
	F(i,1,n)printf("%s\n",a[i]+1);
}	return 0;
}