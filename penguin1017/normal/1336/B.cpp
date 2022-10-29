#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
const ll maxn=3e18+1;
int a[3][N],c[3];
int p[6][3]={0,1,2,0,2,1,1,0,2,1,2,0,2,0,1,2,1,0};
ll ans;
ll get(ll x,ll y,ll z){
	return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}
void solve(int id1,int id2,int id3){
	ll x,y1=0,y2=1e9,z;
	rep(p1,0,c[id1]){
		x=a[id1][p1];
		int p2=lower_bound(a[id2],a[id2]+c[id2],x)-a[id2];
		if(p2>=c[id2])break;
		int p3=lower_bound(a[id3],a[id3]+c[id3],a[id2][p2])-a[id3];
		if(p3>=c[id3])break;
		z=a[id3][p3];
		int mid=x+z;
		mid=mid/2+(mid&1);
		p2=lower_bound(a[id2],a[id2]+c[id2],mid)-a[id2];
		if(p2>=c[id2])y1=y2=a[id2][p2-1];
		else if(!p2)y1=y2=a[id2][p2];
		else y1=a[id2][p2-1],y2=a[id2][p2];
		ans=min(ans,get(x,y1,z));
		ans=min(ans,get(x,y2,z));
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		rep(i,0,3)scanf("%d",&c[i]);
		rep(i,0,3){
			rep(j,0,c[i])scanf("%d",&a[i][j]);
			sort(a[i],a[i]+c[i]);
		}
		ans=maxn;
		rep(i,0,6){
			solve(p[i][0],p[i][1],p[i][2]);
		}
		printf("%lld\n",ans);
	}
}