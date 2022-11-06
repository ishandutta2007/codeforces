#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%I64d",&x); }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int main(){
	ll n,h,k;
	read(n,h,k);
	ll cur=0, now=0;
	for(int i=0; i<n; ++i){
		ll x;
		read(x);
		if(cur+x>h){
			ll over=(cur+x-h+k-1)/k;
			now += over;
			cur -= over*k;
			if(cur<0) cur=0;
		}
		cur += x;
	}
	now += (cur+k-1)/k;
	printf("%I64d\n",now);
	return 0;
}