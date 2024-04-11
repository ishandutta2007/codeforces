#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define EL << "\n"
#define sqr(x) ((x)*(x))
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

template <class T1,class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator << (ostream& out, vector<T> v) {
	out << "[";
	for (auto it = v.begin(); it < v.end(); it++) {
		if (it != v.begin())
			out << ",";
		out << *it;
	}
	out << "]";
	return out;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();

/******************************************/

long long dp[101][101];
int last[26];

int main() {
	int n,k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	dp[101][101]; //first n distinct k
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
		
	for (int i = 0; i < 26; i++)
		last[i] = -1;
		
	for (int i = 1; i <= n; i++) {		
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			if (last[s[i-1]-'a'] != -1)
				dp[i][j] -= dp[last[s[i-1]-'a']-1][j-1];
		}
		last[s[i-1]-'a'] = i;
	}
	
	int cost = 0;
	
	for (int i = n; i >= 0; i--) {
		if (k <= dp[n][i]) {
			cost += k*(n-i);
			cout << cost;
			return 0;
		} else {
			cost += dp[n][i]*(n-i);
			k -= dp[n][i];
		}
	}
	
	cout << -1;
	
	return 0;
}