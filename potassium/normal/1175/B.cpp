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

int main() {
	int l;
	cin >> l;
	stack<pair<int, ll> > s;
	
	bool isOverflow = 0;
	
	while (l--) {
		string ss;
		cin >> ss;
		if (ss == "add")
			s.push({0,1});
		if (ss == "for") {
			ll n;
			cin >> n;
			s.push({1,n});
		}
		if (ss == "end") {
			ll cnt = 0;
			while (s.top().first == 0) {
				cnt += s.top().second;
				s.pop();
			}
			ll mul = s.top().second;
			s.pop();
			ll ans = cnt*mul;
			if (ans > 4294967295) {
				isOverflow = 1;
				break;
			}
			s.push({0,ans});
		}
	}
	
	ll ans = 0;
	while (!s.empty()) {
		ans += s.top().second;
		s.pop();
		if (ans > 4294967295) {
			isOverflow = 1;
			break;
		}
	}
	
	if (isOverflow) {
		cout << "OVERFLOW!!!";
		return 0;
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