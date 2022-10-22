#include<bits/stdc++.h>
#define int long long
#define lb long double
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
int n,m;
int a[400005];
int d[5][2]={
1,0,
-1,0,
0,1,
0,-1,
0,0
};
#define get(i,j) ((i-1)*m+j)
int sum[400005],cnt,bb[400005];
bool check(int x,int y){
	if(a[get(x,y)]==1)RE 1;
	rep(i,0,4){
		int tx=x+d[i][0],ty=y+d[i][1];
		if(tx<1||ty<1||tx>n||ty>m)continue;
		if(a[get(tx,ty)]<a[get(x,y)])RE 1;
	}
	RE 0;
}
P<int,int> bad[400005];
int len; 
int op[400005];
int in[400005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)FOR(j,1,m)cin>>a[get(i,j)];
	FOR(i,1,n){
		FOR(j,1,m)if(a[get(i,j)]!=1){
			bool ff=0;
			rep(k,0,4){
				int x=i+d[k][0],y=j+d[k][1];
				if(x<1||y<1||x>n||y>m)continue;
				if(a[get(x,y)]<a[get(i,j)]){
					ff=1;break;
				}
			}
			if(!ff){
				cnt++;
				rep(k,0,5){
					int x=i+d[k][0],y=j+d[k][1];
					if(x<1||y<1||x>n||y>m)continue;
					sum[get(x,y)]++;
				}
				bb[get(i,j)]++;
			}
		}
	}
	FOR(i,1,n)FOR(j,1,m)if(bb[get(i,j)])bad[++len]=MP(i,j);
	if(!len){
		cout<<0;RE 0;
	}
	if(cnt>10){
		cout<<2;RE 0;
	}
	V<P<int,int> > pos;
	FOR(i,1,len){
		rep(k,0,5){
			int x=bad[i].F+d[k][0],y=bad[i].S+d[k][1];
			if(x<1||y<1||x>n||y>m)continue;
			pos.PB(MP(x,y));
		}
	}
	sort(ALL(pos));
	pos.erase(unique(ALL(pos)),pos.end());
	int now=0,ans=0;
	for(auto u:pos)in[get(u.F,u.S)]=1;
	FOR(i,1,n)FOR(j,1,m)for(auto u:pos){
		++now;
		if(MP(i,j)==u)continue;
		if(in[get(i,j)]&&get(i,j)>get(u.F,u.S))continue;
		int cut=0;
		rep(k,0,5){
			int x=i+d[k][0],y=j+d[k][1];
			if(x>=1&&y>=1&&x<=n&&y<=m){
				cut+=bb[get(x,y)]>0;op[get(x,y)]=now;
			}
		}
		rep(k,0,5){
			int x=u.F+d[k][0],y=u.S+d[k][1];
			if(x>=1&&y>=1&&x<=n&&y<=m){
				cut+=bb[get(x,y)]>0&&op[get(x,y)]!=now;
			}
		}
//		cout<<i<<' '<<j<<' '<<u.F<<' '<<u.S<<' '<<cut<<'\n';
		if(cut!=len)continue;
		bool ff=1;
		swap(a[get(i,j)],a[get(u.F,u.S)]);
		rep(k,0,5){
			int x=i+d[k][0],y=j+d[k][1];
			if(x>=1&&y>=1&&x<=n&&y<=m){
				if(!check(x,y)){
					ff=0;break;
				}
			}
		}
		if(ff)rep(k,0,5){
			int x=u.F+d[k][0],y=u.S+d[k][1];
			if(x>=1&&y>=1&&x<=n&&y<=m){
				if(!check(x,y)){
					ff=0;break;
				}
			}
		}
		swap(a[get(i,j)],a[get(u.F,u.S)]);
		ans+=ff;
	}
	if(!ans)cout<<2;else cout<<1<<' '<<ans;
	RE 0;
}