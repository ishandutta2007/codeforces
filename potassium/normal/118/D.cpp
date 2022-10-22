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

long long dp[101][101][2];
int n[2],k[2];
 
inline long long solve(int n1, int n2, int f) {
	if (dp[n1][n2][f] != -1)
		return dp[n1][n2][f];
	if (n1 == 0 && n2 == 0)
		return 1;
	if (n1 < 0 || n2 < 0)
		return 0;
	
	long long ans = 0;
	if (f == 0)
		for (int i = 1; i <= k[0] && n1-i >= 0; i++)
			ans += solve(n1-i,n2,1) % 100000000;
	else
		for (int i = 1; i <= k[1] && n2-i >= 0; i++)
			ans += solve(n1,n2-i,0) % 100000000;
	dp[n1][n2][f] = ans % 100000000;
	return ans;
}
 
int main() {
	cin >> n[0] >> n[1] >> k[0] >> k[1];
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = -1;
		
	cout << (solve(n[0],n[1],0) + solve(n[0],n[1],1)) % 100000000;
	
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