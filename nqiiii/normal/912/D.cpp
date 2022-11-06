#include<set>
#include<queue>
#include<cstdio>
typedef long long ll;
const int dir[4][2]={0,1,1,0,0,-1,-1,0};
using namespace std;
ll n,m,r,tot,k;
struct nd{
	ll x,y,v;
	nd(ll x,ll y):x(x),y(y){
		v=1;
		ll up=max(x-r+1,1ll),down=min(x,n-r+1); v*=(down-up+1);
		up=max(y-r+1,1ll); down=min(y,m-r+1); v*=(down-up+1);
	}
	bool operator<(const nd &t)const{
		return v<t.v;
	}
};
priority_queue<nd> h;
set<pair<ll,ll> > st;
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&r,&k);
	h.push(nd((n+1)/2,(m+1)/2)); st.insert(make_pair((n+1)/2,(m+1)/2));
	for(int i=1;i<=k;++i){
		nd x=h.top(); h.pop(); tot+=x.v;
		for(int j=0;j<4;++j){
			nd e(x.x+dir[j][0],x.y+dir[j][1]);
			if(st.count(make_pair(e.x,e.y))) continue;
			st.insert(make_pair(e.x,e.y)); h.push(e);
		}
	}
	printf("%.10lf",1.0*tot/(n-r+1)/(m-r+1)); return 0;
}