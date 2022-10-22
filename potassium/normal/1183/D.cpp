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

int cnt[200007];

int main() {
	int q;
	cin >> q;
	
	int x;
	
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		
		for (int j = 1; j <= n; j++)
			cnt[j] = 0;
			
		for (int j = 0; j < n; j++) {
			cin >> x;
			cnt[x]++;
		}
		
		vector<int> v;
		v.reserve(200007);
		
		for (int j = 1; j <= n; j++)
			if (cnt[j] > 0)
				v.push_back(cnt[j]);
		
		sort(v.begin(),v.end());
		
		int ans = 0;
		int cur = INF;
		
		for (int j = v.size()-1; j >= 0; j--) {
			cur = min(cur-1,v[j]);
			if (cur <= 0)
				break;
			ans += cur;
		}
		
		cout << ans EL;
	}
	
	return 0;
}