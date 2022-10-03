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
int a[MN],b[MN],f[MN],g[MN];
vector<int>G;
char s[MN];
void chk(int x){
	char t[15][15];
	int y=12/x;
	F(i,1,x)F(j,1,y)t[i][j]=s[(i-1)*y+j];
//	F(i,1,x){F(j,1,y)printf("%c",t[i][j]);puts("");}
	F(i,1,y){int ok=1;F(j,1,x)if(t[j][i]=='O')ok=0;if(ok){G.push_back(x);return;}}
	return;
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s",s+1);
	G.clear();
	chk(1);
	chk(2);
	chk(3);
	chk(4);
	chk(6);
	chk(12);
	printf("%d ",(int)G.size());
	for(auto x:G)printf("%dx%d ",x,12/x);puts("");
}	return 0;
}