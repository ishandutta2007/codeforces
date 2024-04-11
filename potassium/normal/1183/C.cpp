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

int a[105];

int main() {
	int q;
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		long long k,n,a,b;
		cin >> k >> n >> a >> b;
		
		long long cur = b*n;
		
		if (k - cur >= 1) {
			long long ans = (k-cur-1)/(a-b);
			cout << min(ans,n) EL;
		} else {
			cout << -1 EL;
		}
	}
	
	return 0;
}