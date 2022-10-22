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
ll len[100007];
ll lencnt[11];
ll plencnt[11];
ll sum[11][20];
ll psum[11][20];
ll total[20];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		len[i] = a[i].length();
		lencnt[len[i]]++;
		reverse(a[i].begin(),a[i].end());
		for (int j = 0; j < len[i]; j++)
			psum[len[i]][j] += (a[i][j] - '0');
	}
	
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 20; j++)
			psum[i][j] += psum[i-1][j];
			
	for (int i = 0; i < 11; i++)
		plencnt[i] = plencnt[i-1] + lencnt[i];
	
	for (int lens = 1; lens < 11; lens++) {
		for (int j = 0; j < lens; j++) {
			ll incre = psum[lens][j] - psum[lens-1][j];
			incre *= n-plencnt[lens-1];
			incre %= MOD2;
			total[2*j] += incre;
			total[2*j+1] += incre;
		}
		for (int j = 0; j < lens; j++) {
			ll incre = psum[10][j] - psum[lens][j];
			incre *= lencnt[lens];
			incre %= MOD2;
			total[2*j] += incre;
			total[2*j+1] += incre;
		}
		for (int j = lens; j < 20; j++) {
			ll incre = psum[10][j] - psum[lens][j];
			incre *= 2 * lencnt[lens];
			total[j+lens] += incre;
		}
	}
	
	ll ans = 0;
	ll curmul = 1;
	for (int lens = 0; lens < 20; lens++) {
		ans += total[lens] * curmul;
		ans %= MOD2;
		curmul *= 10;
		curmul %= MOD2;
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