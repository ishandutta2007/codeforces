#pragma GCC optimize(2)
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
using namespace std;
int a[50005][6];
P<P<int,int>,P<int,int> > p[50005];
bool out[50005];
int maxi[50005];
int n;
void update(int x,int y){
	while(x){
		gmax(maxi[x],y);
		x-=x&-x;
	}
}
int get(int x){
	int re=0;
	while(x<=50000){
		gmax(re,maxi[x]);
		x+=x&-x;
	}
	RE re;
}
void solve(){
	cin>>n;
	int m=5;
	FOR(i,1,n)out[i]=0;
	FOR(i,1,n)rep(j,0,m)cin>>a[i][j],a[i][j]=50000-a[i][j]+1;
	rep(mask,0,1<<5){
		int cnt=0,it[5];
		rep(j,0,m)if(mask&(1<<j))it[cnt++]=j;
		if(cnt==3){
			FOR(i,1,n){
				p[i]=MP(MP(a[i][it[0]],a[i][it[1]]),MP(a[i][it[2]],i));
			}
			FOR(i,1,50000)maxi[i]=0;
			sort(p+1,p+n+1);
			reverse(p+1,p+n+1);
			FOR(i,1,n){
				if(get(p[i].F.S)>p[i].S.F){
					out[p[i].S.S]=1;
				}
				update(p[i].F.S,p[i].S.F);
			}
		}
	}
	FOR(i,1,n)if(!out[i]){
		cout<<i<<'\n';RE;
	}
	cout<<-1<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}