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

int main() {
	int q;
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		long long x;
		cin >> x;
		
		int ans = 0;
		
		while (x % 5 == 0) {
			x /= 5;
			ans += 3;
		}
		
		while (x % 3 == 0) {
			x /= 3;
			ans += 2;
		}
		
		while (x % 2 == 0) {
			x /= 2;
			ans++;
		}
		
		if (x != 1)
			cout << -1;
		else
			cout << ans;
		cout EL;
	}
	
	return 0;
}