#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << ' '
#define EL << '\n'
#define WSP cout << ' '
#define WEL cout << '\n'
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
typedef long long ll;
using namespace std;
template <class T1, class... T2> inline void R(T1 &x, T2 &...y);
template <class T1, class... T2> inline void W(T1 &x, T2 &...y);
template <class T1, class T2> inline ostream& operator << (ostream& out, pair<T1,T2> p);
inline ostream& operator << (ostream& out, string& s);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

ll a[300007];
ll s[300007];

int main() {
	int n,k;
	R(n,k);
	for (int i = 0; i < n; i++)
		R(a[i]);
	s[n] = 0;
	for (int i = n-1; i >= 0; i--)
		s[i] = s[i+1] + a[i];
	ll ans = s[0];
	sort(s+1,s+n);
	for (int i = n-1; i > n-k; i--)
		ans += s[i];
	W(ans);	
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
template <class T> inline void _R(T &x) {cin >> x;}
inline void R() {}
template <class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}
template <class T> inline void _W(T &x) {cout << x << ' ';}
inline void W() {}
template <class T1, class... T2> inline void W(T1 &x, T2 &...y) { _W(x); W(y...);}
template <class T1, class T2> inline ostream& operator << (ostream& out, pair<T1,T2> p) {return out << '(' << p.first << ',' << p.second << ')';}
inline ostream& operator << (ostream& out, string& s) {for (int i = 0; i < s.length(); i++) out << s[i]; return out;}
template <template <class...> class _TContainer, class... _T> inline ostream& operator << (ostream& out, _TContainer<_T...>& _Container) {bool first = 1;	out << '['; for(auto x : _Container) {if (!first) out << ','; out << x; first = 0;} out << ']'; return out;}