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

ll dp[100007][2]; // last = T/L
ll curmax0, curmax1;
ll a[100007],b[100007];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
		
	dp[0][0] = curmax0 = a[0];
	dp[0][1] = curmax1 = b[0];
	
	for (int i = 1; i < n; i++) {
		dp[i][0] = curmax1 + a[i];
		dp[i][1] = curmax0 + b[i];
		curmax1 = max(curmax1,dp[i][1]);
		curmax0 = max(curmax0,dp[i][0]);
	}
	
	cout << max(curmax1,curmax0);	
	
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