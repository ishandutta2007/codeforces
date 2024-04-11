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

string a[100007];
ll b[100007];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	int len = a[0].length();
	
	ll sum = 0;
	
	for (int i = 0; i < n; i++) {
		b[i] = 0;
		for (int j = 0; j < len; j++) {
			b[i] *= 100;
			b[i] += (a[i][j]-'0')*11;
			b[i] %= MOD2;
		}
		sum += b[i];
		sum %= MOD2;
	}
	
	ll ans = sum*n;
	ans %= MOD2;
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