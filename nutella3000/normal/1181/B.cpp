#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;

string to_int(string a, string b) {
	deque<int> c;
	int lst = 0;
	for(int i = 0;i < max(sz(a), sz(b));i++) {
		int num = lst;
		if (sz(a) - i - 1 >= 0) num += a[sz(a) - i - 1] - '0';
		if (sz(b) - i - 1 >= 0) num += b[sz(b) - i - 1] - '0';
		c.emplace_front(num % 10);
		lst = num / 10;
	}
	if (lst != 0) c.emplace_front(lst);
	string d;
	for(int i : c)
		d += (char) (i + '0');
	return d;
}

bool less_(string a, string b) {
	if (sz(a) != sz(b)) return sz(a) < sz(b);
	return a < b;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    string s;
    cin >> n >> s;
    string res = "";

    int it = 0;
    for(int i = max(1ll, n / 2);i < n;i++) {
    	string a = s.substr(0, i);
    	string b = s.substr(i);
    	if (a[0] == '0' || b[0] == '0') continue;
    	if (it > 10) break;
    	it++;
    	string c = to_int(a, b);
    	//cout << c << endl;
    	if (res == "" || less_(c, res)) {
    		res = c;
    	}
    }	

    it = 0;
    for(int i = max(1ll, n / 2);i >= 1;i--) {
    	string a = s.substr(0, i);
    	string b = s.substr(i);
    	if (a[0] == '0' || b[0] == '0') continue;
    	if (it > 10) break;
    	it++;
    	string c = to_int(a, b);
    	//cout << c << endl;
    	if (res == "" || less_(c, res)) {
    		res = c;
    	}
    }

    cout << res;
}