#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

#define int LL

const int MAXN = 15;
struct Node{
	int x,y;
	Node(int x=0,int y=0) : x(x),y(y) {}
}a[5],ans[5],c[5],_[MAXN];
int res;
int opt[MAXN],b[MAXN];
// 0=x ,1=y
std::vector<int> rx,ry;

inline bool cmp1(int x,int y){
	return a[x].x < a[y].x;
}

inline bool cmp2(int x,int y){
	return a[x].y < a[y].y;
}

int p[MAXN];

inline void upmax(int gx){
	if(gx < res){
		res = gx;
		FOR(i,1,4) ans[i] = _[i];
	}
}

inline void upall(){
	FOR(i,1,4) p[i] = i;
	do{
		int gx = 0;
		bool flag = 1;
		FOR(i,1,4){
			int dx = std::abs(c[p[i]].x-a[i].x),dy = std::abs(c[p[i]].y-a[i].y);
			if(dx && dy){
				flag = 0;break;
			}
			_[i] = c[p[i]];
			gx = std::max(gx,dx+dy);
		}
		if(!flag) continue;
		upmax(gx);
	}while(std::next_permutation(p+1,p+4+1));
}

inline void chk(){
	std::sort(all(rx));std::sort(all(ry));
	rx.erase(std::unique(all(rx)),rx.end());
	ry.erase(std::unique(all(ry)),ry.end());
	if(rx.size() == 2 || ry.size() == 2){
		if(rx.size() == 2 && ry.size() == 2){
			if(rx[0] != rx[1] && ry[0] != ry[1]){
				if(rx[1] - rx[0] != ry[1] - ry[0]) return;
				FOR(i,0,1) FOR(j,0,1) c[i*2+j+1] = Node(rx[i],ry[j]);
				upall();
				return;
			}
		}
		if(rx.size() == 2 && ry.size() == 1){
			int D = rx[1]-rx[0];
			FOR(i,0,1) c[i+1] = Node(rx[i],ry[0]);
			FOR(i,3,4) c[i] = c[i-2],c[i].y += D;
			upall();
			FOR(i,3,4) c[i] = c[i-2],c[i].y -= D;
			upall();
			return;
		}
		if(ry.size() == 2 && rx.size() == 1){
			int D = ry[1]-ry[0];
			FOR(i,0,1) c[i+1] = Node(rx[0],ry[i]);
			FOR(i,3,4) c[i] = c[i-2],c[i].x += D;
			upall();
			FOR(i,3,4) c[i] = c[i-2],c[i].x -= D;
			upall();
			return;	
		}
	}
	if(rx.empty() && ry.size() == 2){
		int y1 = ry[0],y2 = ry[1];
		int D = y2-y1;
		std::vector<int> v1,v2;
		FOR(i,1,4){
			if(a[i].y == y1) v1.pb(i);
			else v2.pb(i);
		}
		FOR(_,0,1){
			FOR(i,0,1){
				FOR(j,0,1){
					int mn = std::min({a[v1[0]].x,a[v1[1]].x-D,a[v2[0]].x,a[v2[1]].x-D});
					int mx = std::max({a[v1[0]].x,a[v1[1]].x-D,a[v2[0]].x,a[v2[1]].x-D});
					int tt = (mn+mx)/2;
					// DEBUG(tt);DEBUG(tt+D);
					FOR(x,tt-1,tt+1){
						c[1] = Node(x,y1);c[2] = Node(x+D,y1);
						c[3] = Node(x,y2);c[4] = Node(x+D,y2);
						// FOR(i,1,4) printf("%d %d\n",c[i].x,c[i].y);
						upall();
						// exit(0);
					}
					std::swap(v2[0],v2[1]);
				}
				std::swap(v1[0],v1[1]);
			}
			D = -D;
		}
	}
	if(ry.empty() && rx.size() == 2){
		int x1 = rx[0],x2 = rx[1];
		int D = x2-x1;
		std::vector<int> v1,v2;
		FOR(i,1,4){
			if(a[i].x == x1) v1.pb(i);
			else v2.pb(i);
		}
		FOR(_,0,1){
			FOR(i,0,1){
				FOR(j,0,1){
					int mn = std::min({a[v1[0]].y,a[v1[1]].y-D,a[v2[0]].y,a[v2[1]].y-D});
					int mx = std::max({a[v1[0]].y,a[v1[1]].y-D,a[v2[0]].y,a[v2[1]].y-D});
					int tt = (mn+mx)/2;
					FOR(y,tt-1,tt+1){
						c[1] = Node(x1,y);c[2] = Node(x1,y+D);
						c[3] = Node(x2,y);c[4] = Node(x2,y+D);
						upall();
					}
					std::swap(v2[0],v2[1]);
				}
				std::swap(v1[0],v1[1]);
			}
			D = -D;
		}
	}
}

inline void Solve(){
	FOR(i,1,4) scanf("%lld%lld",&a[i].x,&a[i].y);
	res = 1e18;
	FOR(S,0,(1<<4)-1){
		rx.clear();ry.clear();
		FOR(i,0,3){
			if((S>>i)&1) rx.pb(a[i+1].x);
			else ry.pb(a[i+1].y);
		}
		chk();
	}
	if(res == 1e18){
		puts("-1");
		return;
	}
	printf("%lld\n",res);
	FOR(i,1,4) printf("%lld %lld\n",ans[i].x,ans[i].y);
}

signed main(){
	int T;scanf("%lld",&T);
	while(T--) Solve();
	return 0;
}