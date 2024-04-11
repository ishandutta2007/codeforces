#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int fa[1<<15]; 
bitset<1<<14> f[2];
bitset<1<<15> vis;
int get(int x){
	RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
}
int merge(int x,int y){
	x=get(x);y=get(y);
	if(x==y)RE 0;
	fa[x]=y;
	RE 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	rep(i,0,m)fa[i]=i;
	char c;
	int num;
	int ans=0;
	FOR(i,1,n){
		rep(j,0,m/4){
			cin>>c;
			if(c<='9')num=c-'0';else num=c-'A'+10;
			rep(k,0,4){
				if(num&(1<<k)){
					f[1][j*4-k+3]=1;ans++;
				}else f[1][j*4-k+3]=0;
				fa[m+j*4-k+3]=m+j*4-k+3;
			}
		}
		rep(j,0,m){
//			cout<<f[1][j]<<' ';
			if(j&&f[1][j]&&f[1][j-1]){
				ans-=merge(j+m,j-1+m);
			}
			if(i>1&&f[0][j]&&f[1][j])ans-=merge(j,j+m);
		}
//		cout<<ans<<'\n';
		rep(j,0,m){
			fa[j+m]=get(j+m);
		}
		rep(j,0,m)fa[j]=fa[j+m]-m,f[0][j]=f[1][j];
	}
	cout<<ans;
	RE 0;
}