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
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

int a[1007];
long long dp[1007][1007];
long long ps[1007][1007];

int main() {
	int n,k;
	cin >> n >> k;
	
	a[0] = -INF;
	a[n+1] = INF;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a+1,a+n+1);
	
	long long ans = 0;
		
	for (int i = 1; i <= a[n]/(k-1); i++) {
		for (int j = 0; j <= n; j++)
			for (int l = 0; l <= k; l++)
				dp[j][l] = ps[j][l] = 0;
		
		for (int j = 1; j <= n; j++)
			ps[j][1] = j;
			
		int lp = 0;
		for (int j = 1; j <= n; j++) {
			while (a[j]-a[lp+1]>=i) lp++;
			for (int l = 2; l <= k; l++) {
				dp[j][l] = ps[lp][l-1] % MOD2;
				ps[j][l] = (ps[j-1][l] + dp[j][l]) % MOD2;
			}
		}
		for (int j = 1; j <= n; j++)
		ans = (ans + dp[j][k]) % MOD2;
	}
	
	cout << ans;
}
 
/*
  _____                                               _               _       _                   _ _ 
 |  __ \                                             (_)             (_)     | |                 | | |
 | |__) | __ ___   __ _ _ __ __ _ _ __ ___  _ __ ___  _ _ __   __ _   _ ___  | |__   __ _ _ __ __| | |
 |  ___/ '__/ _ \ / _` | '__/ _` | '_ ` _ \| '_ ` _ \| | '_ \ / _` | | / __| | '_ \ / _` | '__/ _` | |
 | |   | | | (_) | (_| | | | (_| | | | | | | | | | | | | | | | (_| | | \__ \ | | | | (_| | | | (_| |_|
 |_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|_| |_| |_|_|_| |_|\__, | |_|___/ |_| |_|\__,_|_|  \__,_(_)
                   __/ |                                       __/ |                                  
                  |___/                                       |___/                                                                                 
*/
 
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
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();