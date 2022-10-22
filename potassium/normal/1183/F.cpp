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

int main() {
	int q;
	cin >> q;
	
	int x;
	
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		
		set<int> s;
		
		for (int j = 0; j < n; j++) {
			cin >> x;
			s.insert(x);
		}
		
		vector<int> a;
		a.reserve(s.size()+7);
		
		for (auto i : s)
			a.push_back(i);
		
		int ans = a.back();
		
		for (int j = a.size()-1; j >= 0; j--) {
			if (a[j]*3 <= ans)
				break;
			for (int k = j-1; k >= 0; k--) {
				if (a[j]+a[k]*2 <= ans)
					break;
				if (a[j] % a[k] != 0) {
					ans = max(ans,a[j]+a[k]);
					for (int l = k-1; l >= 0; l--) {
						if (a[j]+a[k]+a[l] <= ans)
							break;
						if (a[j] % a[l] != 0 && a[k] % a[l] != 0) {
							ans = max(ans,a[j]+a[k]+a[l]);
							break;
						}
					}
					break;
				}
			}
		}
		
		cout << ans EL;
	}
	
	return 0;
}