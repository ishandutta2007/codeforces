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
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		int cnt[3] = {0,0,0};
		
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			cnt[x % 3]++;
		}
		
		int incre = min(cnt[1],cnt[2]);
		cnt[1] -= incre;
		cnt[2] -= incre;
		
		cout << cnt[0] + incre + cnt[1]/3 + cnt[2]/3 EL;
	}
	
	return 0;
}