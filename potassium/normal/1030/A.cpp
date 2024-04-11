#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define initrand(x) mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
#define initrand64(x) mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	bool flag = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		bool x;
		cin >> x;
		flag = flag || x;
	}
	
	if (flag)
		cout << "HARD";
	else
		cout << "EASY";
					
	return 0;
}