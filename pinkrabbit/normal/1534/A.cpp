#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 55
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
char a[MN][MN],b[MN][MN];
bool chk(){
	F(i,1,n)F(j,1,m){
		int ok=1;
		if(i>1)ok&=b[i][j]!=b[i-1][j];
		else if(j>1)ok&=b[i][j]!=b[i][j-1];
		if(!ok)return 0;
	}
	puts("YES");
	F(i,1,n)printf("%s\n",b[i]+1);
	return 1;
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%s",a[i]+1);
	F(i,1,n){
		F(j,1,m)
			b[i][j]=a[i][j]=='.'?(i+j)&1?'R':'W':a[i][j];
		b[i][m+1]='\0';
	}
	if(chk())continue;
	F(i,1,n)F(j,1,m)
		b[i][j]=a[i][j]=='.'?(i+j)&1?'W':'R':a[i][j];
	if(!chk())puts("NO");
}	return 0;
}