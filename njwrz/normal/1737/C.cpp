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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
P<int,int> p[3];
void solve(){
	int n;
	cin>>n;
	rep(i,0,3){
		cin>>p[i].F>>p[i].S;
	}
	int x,y;
	cin>>x>>y;
	rep(i,0,3){
		if(p[i]==MP(x,y)){
			cout<<"YES\n";RE;
		}
	}
	P<int,int> to=MP(x,y);
	bool tf=0;
	rep(i,0,3)if((p[i].F>1&&p[i].F<n)&&p[i].S>1&&p[i].S<n){
		tf=1;break;
	}
	if(!tf){
	rep(i,0,3){
		if(p[i]==MP(1,1)){
			if(x==1||y==1){
				cout<<"YES\n";
			}else cout<<"NO\n";
			RE ;
		}else if(p[i]==MP(n,1)){
			if(x==n||y==1){
				cout<<"YES\n";
			}else cout<<"NO\n";
			RE ;
		}else if(p[i]==MP(1,n)){
			if(x==1||y==n){
				cout<<"YES\n";
			}else cout<<"NO\n";
			RE;
		}else if(p[i]==MP(n,n)){
			if(x==n||y==n){
				cout<<"YES\n";
			}else cout<<"NO\n";
			RE;
		}
	}
		
	}
	int lx=n,ly=n,rx=1,ry=1;
	rep(i,0,3){
		gmin(lx,p[i].F);gmax(rx,p[i].F);
		gmin(ly,p[i].S);gmax(ry,p[i].S);
	}
	int tx,ty;
	FOR(i,lx,rx)FOR(j,ly,ry){
		bool f=0;
		rep(k,0,3)if(MP(i,j)==p[k]){
			f=1;break;
		}
		if(!f){
			tx=i&1;ty=j&1;
		}
	}
//	cout<<tx<<' '<<ty<<'\n';
	if((x&1)==(tx&1)&&(y&1)==(ty&1)){
		cout<<"NO\n";
	}else cout<<"YES\n";
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}