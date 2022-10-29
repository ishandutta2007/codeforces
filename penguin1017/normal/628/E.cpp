#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
#define lowbit(x) ((x)&(-x)) 
#define pb push_back
using namespace std;
const int N=3005;
vector<int> g[N*2]; 
int sum[N*2],L[N][N],R[N][N],n,m;
char s[N][N];
void Set(int p,int val){
	for(int i=p;i<N*2;i+=lowbit(i))sum[i]+=val;
}
int Get(int p){
	int res=0;
	for(int i=p;i;i^=lowbit(i))res+=sum[i];
	return res;
}
ll solve(int x,int y){
//	if(x==1&&y==4)system("pause");
	memset(sum,0,sizeof(sum));
	rep(i,1,2*N)g[i].clear();
	int lx=x,ly=y;
	ll res=0;
	while(x<=n&&y>=1){
		if(s[x][y]=='.'){
			for(int i=lx,j=ly;i<x;i++,j--){
				if(i+L[i][j]>=x)Set(i,-1),g[i+L[i][j]].clear();
			}
			lx=++x,ly=--y;
		}
		else{
			for(auto p:g[x])Set(p,-1);
			Set(x,1);
			g[x+L[x][y]].pb(x);
			res+=Get(x);
			if(x>R[x][y])res-=Get(x-R[x][y]);
		//	cout<<x<<' '<<y<<' '<<' '<<Get(x)<<' '<<res<<"res\n";
			++x,--y;
		}
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)scanf("%s",s[i]+1);
	rep(i,1,n+1){
		rep(j,1,m+1)if(s[i][j]=='z')L[i][j]=L[i][j-1]+1;
		per(j,1,m+1)if(s[i][j]=='z')R[i][j]=R[i][j+1]+1;
	} 
	ll ans=0;
	rep(i,1,m+1){
		ans+=solve(1,i);
		//cout<<solve(1,i)<<"solve\n";
	}
	rep(i,2,n+1){
		ans+=solve(i,m);
	}
	printf("%lld",ans);
 } 
 /*
4 4 
z..z
z.z.
..zz
z.zz

4 4
zzzz
zzz.
.z..
zzzz
*/