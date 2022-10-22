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
	
	int a[3],d;
	cin >> a[0] >> a[1] >> a[2] >> d;
	
	sort(a,a+3);
	
	int ans = max(0,d-a[1]+a[0]) + max(0,d-a[2]+a[1]);
	
	cout << ans;
					
	return 0;
}