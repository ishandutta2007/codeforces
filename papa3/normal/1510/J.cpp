#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

template<class C> void mini(C &a5, C b5) { a5 = min(a5, b5); }
template<class C> void maxi(C &a5, C b5) { a5 = max(a5, b5); }

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;

vector<int> res;
bool check(const vector<int> &v, int x) {
	res.clear();
	
	for (int i = 0; i < (int)v.size(); i += 2) {
		int l = v[i];
		l -= x;
		if (l < 0) {
			return false;
		}
		if (x == 0 && l == 0) {
			return false;
		}
		
		if (l % 2) {
			if (l == 1 || x < 2) {
				return false;
			}
			res.push_back(2);
			l -= 3;
		}
		
		for (int j = 0; j < l / 2; j++) {
			res.push_back(1);
		}
		
		if (i + 1 < (int)v.size()) {
			res.push_back(v[i + 1] + 1 + x);
		}
	}
	
	return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    vector<int> v;
    
    if (s.front() == '#' || s.back() == '#') {
		if (s.front() == '_' || s.back() == '_') {
			cout << "-1\n\n";
			return 0;
		}
		
		int li = 1;
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] != s[i - 1]) {
				if (s[i - 1] == '#')
					res.push_back(li);
				li = 0;
			} if (s[i] == '_' && li > 0) {
				cout << "-1\n\n";
				return 0;
			}
			li++;
		}
		res.push_back(li);
		
		cout << res.size() << "\n";
		for (int j : res) {
			cout << j << " ";
		}
		cout << "\n";
		return 0;
	}
 
	int li = 1;
    for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] != s[i - 1]) {
			v.push_back(li - 1);
			li = 0;
		}
		li++;
	}
	v.push_back(li - 1);
	v.front()++;
	v.back()++;
	
	for (int i : v) {
		cerr << i << " ";
	}
	cerr << "\n";
	
	if (v.size() == 1) {
		cout << "0\n\n";
		return 0;
	}
	
	for (int i = 1; i < 5; i++) {
		if (check(v, i)) {
			cerr << "i = " << i << "\n";
			cout << res.size() << "\n";
			for (int j : res) {
				cout << j << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	
	cout << "-1\n";
    
    return 0;
}/*
__#_____

_#

___


_#__#__#_
3
2 2 2

___#__#__#_
4
1 2 2 2

___##___##_##__
-1

__##___#____

#_#_#
#
###_#####_#_#
*/