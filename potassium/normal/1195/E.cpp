#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << " "
#define EL << "\n"
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
typedef long long ll;
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

ll minv[3001][3001];
ll val[3001][3001];

int main() {
	int a,b,n,m;
	cin >> n >> m >> a >> b;
	
	ll g,x,y,z;
	cin >> g >> x >> y >> z;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			val[i][j] = g;
			g = (g*x+y) % z;
		}
	}
	
	for (int i = 0; i < n; i++) {
		deque<ll> s;
		for (int j = 0; j < m; j++) {
			if (j-b >= 0 && s.front() == val[i][j-b]) s.pop_front();
			while (!s.empty() && s.back() > val[i][j])
				s.pop_back();
			s.pb(val[i][j]);
			minv[i][j] = s.front();
		}
	}
	
	ll ans = 0;
	
	for (int j = b-1; j < m; j++) {
		deque<ll> s;
		for (int i = 0; i < n; i++) {
			if (i-a >= 0 && s.front() == minv[i-a][j]) s.pop_front();
			while (!s.empty() && s.back() > minv[i][j])
				s.pop_back();
			s.pb(minv[i][j]);
			if (i >= a-1) ans += s.front();
		}
	}
	
	cout << ans;
	
	return 0;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
template <class T1, class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << '(' << p.first << ',' << p.second << ')';
}
template <template <class...> class _TContainer, class... _T>
ostream& operator << (ostream& out, _TContainer<_T...>& _Container) {	
    out << '[';
    bool first = 1;
    for(auto x : _Container) {
    	if (!first) out << ',';
    	out << x;
    	first = 0;
    }
    out << ']';
    return out;
}