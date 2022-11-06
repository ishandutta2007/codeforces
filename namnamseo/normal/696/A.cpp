#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
//void read(ll& x){ scanf("%I64d",&x); }
void read(ll& x){ cin >> x; }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

map<ll,ll> inc;

int level(ll x){
	for(int i=0; ; ++i) if((1LL<<i) > x) return i-1;
}

int main(){
	int q; read(q);
	for(;q--;){
		int com; read(com);
		if(com == 1){
			ll a,b; int c;
			read(a, b, c);
			if(level(a) > level(b)) swap(a,b);
			int df=level(b)-level(a);
			for(;df--;){
				inc[b] += c;
				b/=2;
			}
			if(a>b) swap(a,b);
			while(a<b){
				inc[a] += c;
				inc[b] += c;
				a/=2; b/=2;
			}
		} else {
			ll a,b; read(a,b);
			ll ans=0;
			if(level(a) > level(b)) swap(a,b);
			int df=level(b)-level(a);
			for(;df--;){
				if(inc.find(b) != inc.end()) ans += inc[b];
				b/=2;
			}
			if(a>b) swap(a,b);
			while(a<b){
				if(inc.find(a) != inc.end()) ans += inc[a];
				if(inc.find(b) != inc.end()) ans += inc[b];
				a/=2; b/=2;
			}
			printf("%I64d\n", ans);
		}
	}
	return 0;
}