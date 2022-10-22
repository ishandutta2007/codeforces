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
int n;
double x,y,x2,y2;
double p[300005],q[300005];
int T;
void solve(){
	cin>>n>>y>>x;x2=x;y2=y;
	multiset<P<double,double> > s;
	FOR(i,1,n)cin>>p[i];
	FOR(i,1,n)cin>>q[i];
	FOR(i,1,n){
		if(!x&&!y){
			printf("%.10f\n",x);continue;
		}
		x-=q[i];y+=p[i];x2+=q[i];y2-=p[i];
		s.emplace(MP(p[i]/q[i],q[i]*2));
		while(x<0&&!s.empty()){
			P<double,double> now=*s.begin();s.erase(s.lwb(now));
			if(x+now.S<=0){
				y-=now.F*now.S;
				x+=now.S;
			}else{
				y+=x*now.F;
				now.S+=x;
				s.emplace(now);
				x=0;
			}
		}
		while(y2<0&&!s.empty()){
			P<double,double> now=*s.rbegin();s.erase(s.lwb(now));
			if(y2+now.F*now.S<=0){
				y2+=now.F*now.S;
				x2-=now.S;
			}else{
				x2+=y2/now.F;
				now.S+=y2/now.F;
				y2=0;
				s.emplace(now);
			}
		}
		printf("%.10f\n",y);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--)solve();
	RE 0;
}