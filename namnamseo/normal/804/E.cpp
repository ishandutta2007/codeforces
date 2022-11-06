#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

const vector<pp> sol4{
	{0, 1},
	{0, 2},
	{1, 3},
	{0, 3},
	{1, 2},
	{2, 3}
};

vector<pp> solve(int n){
	if(n == 1) return {};
	if(n == 4) return sol4;
	if(n%2 == 1){
		auto v = solve(n-1);
		vector<pp> ret;
		ret.reserve(n*(n-1)/2);
		for(auto t:v){
			int x, y; tie(x, y) = t;
			if(x+1 == y && x%2 == 0){
				ret.eb(x, n-1);
				ret.eb(x, y);
				ret.eb(y, n-1);
			} else {
				ret.pb(t);
			}
		}
		return ret;
	}
	auto v = solve(n-4);
	vector<pp> ret;
	for(auto t:sol4){
		int x, y; tie(x, y) = t;
		ret.eb(x+n-4, y+n-4);
	}
	for(auto t:v){
		int x, y; tie(x, y) = t;
		if(x+1 == y && x%2 == 0){
			ret.eb(x, n-4);
			ret.eb(x, n-3);
			ret.eb(x, n-2);
			ret.eb(x, n-1);
			ret.eb(x, y);
			ret.eb(y, n-1);
			ret.eb(y, n-2);
			ret.eb(y, n-3);
			ret.eb(y, n-4);
		} else {
			ret.pb(t);
		}
	}
	return ret;
}

int main()
{
	int n;
	read(n);
	if(n%4 == 2 || n%4 == 3){
		puts("NO"); return 0;
	}
	puts("YES");
	for(auto t:solve(n)){
		printf("%d %d\n", t.x+1, t.y+1);
	}
	return 0;
}