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
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

char a[1001][1001];
long long dp[2001][2001];
long long n,m,q;

inline long long solve(int x, int y) {
	if (x == 0 || y == 0)
		return 0;
	
	long long inx = x/(2*n), iny = y/(2*m);	
	long long corx = inx*2*n, cory = iny*2*m;
	long long ans = (y*corx)/2 + (x*cory)/2 - (corx*cory)/2;
	if (x > corx && y > cory) {
		int cnt = 0;
		while (inx > 0) {
			cnt += inx % 2;
			inx /= 2;
		}
		while (iny > 0) {
			cnt += iny % 2;
			iny /= 2;
		}
		if (cnt % 2 == 1)
			ans += (x-corx)*(y-cory) - dp[x-corx][y-cory];
		else
			ans += dp[x-corx][y-cory];
	}
	
	return ans;
}

int main() {
     cerr << "TESTING!";
	cin >> n >> m >> q;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
			
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= m; j++)
			dp[i][j] = dp[i][j-1] + a[i][j] - '0';
		for (int j = m+1; j <= 2*m; j++)
			dp[i][j] = dp[i][j-1] + '1' - a[i][j-m];
	}
	
	for (int i = n+1; i <= 2*n; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= m; j++)
			dp[i][j] = dp[i][j-1] + '1' - a[i-n][j];
		for (int j = m+1; j <= 2*m; j++)
			dp[i][j] = dp[i][j-1] + a[i-n][j-m] - '0';
	}
	
	for (int i = 2; i <= 2*n; i++)
		for (int j = 1; j <= 2*m; j++)
			dp[i][j] += dp[i-1][j];
	
	while (q--) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << solve(x2,y2) - solve(x1-1,y2) - solve(x2,y1-1) + solve(x1-1,y1-1) EL;
	}
	
	return 0;
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