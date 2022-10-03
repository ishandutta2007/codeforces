#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m;
char s[MN][MN];
int a[MN],b[MN],c[MN],d[MN];
int v[MN][MN];
void dfs(int x,int y){
	v[x][y]=1;
	if(s[x-1][y]=='#'&&!v[x-1][y])dfs(x-1,y);
	if(s[x+1][y]=='#'&&!v[x+1][y])dfs(x+1,y);
	if(s[x][y-1]=='#'&&!v[x][y-1])dfs(x,y-1);
	if(s[x][y+1]=='#'&&!v[x][y+1])dfs(x,y+1);
}
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%s",s[i]+1);
	int ok=1;
	F(i,1,n){
		a[i]=b[i]=0;
		F(j,1,m)if(s[i][j]=='#'){
			a[i]=a[i]?a[i]:j;
			b[i]=j;
		}
		if(a[i])F(j,a[i],b[i])if(s[i][j]=='.')ok=0;
	}
	F(j,1,m){
		c[j]=d[j]=0;
		F(i,1,n)if(s[i][j]=='#'){
			c[j]=c[j]?c[j]:i;
			d[j]=i;
		}
		if(c[j])F(i,c[j],d[j])if(s[i][j]=='.')ok=0;
	}
	if(!ok)return puts("-1"),0;
	int _x=0,_y=0;
	F(i,1,n)if(!a[i])_x=1;
	F(j,1,m)if(!c[j])_y=1;
	if(_x^_y)return puts("-1"),0;
	int ans=0;
	F(i,1,n)F(j,1,m)if(s[i][j]=='#'&&!v[i][j])++ans,dfs(i,j);
	printf("%d\n",ans);
	return 0;
}