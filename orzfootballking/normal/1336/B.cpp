#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
using namespace std;
int f[6][3]={
0,1,2,
1,0,2,
2,0,1,
0,2,1,
1,0,2,
2,1,0
};
int a[3][100005],l[3],m=3,ans;
int b[3][100005],tl[3];
void get(int x,int y,int z){
	int t=(b[0][x]-b[1][y])*(b[0][x]-b[1][y])+
	(b[0][x]-b[2][z])*(b[0][x]-b[2][z])+
	(b[1][y]-b[2][z])*(b[1][y]-b[2][z]);
	if(ans==-1||ans>t)ans=t;
}
void check(int p){
	rep(i,0,m){
		tl[i]=l[f[p][i]];
		FOR(j,1,tl[i])b[i][j]=a[f[p][i]][j];
	}
	if(b[0][tl[0]]<b[1][1])RE;
	int st=1,t;
	FOR(i,1,tl[0]){
		while(st<=tl[1]&&b[1][st]<=b[0][i])st++;
		t=lower_bound(b[2]+1,b[2]+tl[2]+1,(b[1][st-1]+b[0][i])>>1)-b[2];
		if(t<=tl[2]&&st>1)get(i,st-1,t);
		t--;
		if(t>0&&st>1)get(i,st-1,t);
	}
}
void solve(){
	rep(i,0,m)cin>>l[i];
	rep(i,0,m){
		FOR(j,1,l[i])cin>>a[i][j];
		sort(a[i]+1,a[i]+l[i]+1);
	}
	ans=-1;
	rep(i,0,6)check(i);
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}