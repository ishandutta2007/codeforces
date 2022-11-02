#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
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

const int inf = 1e9 + 4;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    string s;
   	int x, y, n;
   	cin >> s >> x >> y;
   	n = sz(s);
   	if (x > y) {
   		swap(x, y);
   		for(char &i : s) {
   			if (i != '?') i = ('1' - i) + '0';
   		}
   	}

   	int sum = 0;

   	int all_c0 = 0, all_c1 = 0;
   	vector<int> c0(n), c1(n);

   	vector<int> a;

   	for(int i = 0;i < n;i++) {
   		if (i != 0) {
   			c0[i] = c0[i - 1];
   			c1[i] = c1[i - 1];
   		}
   		if (s[i] == '?') {
   			a.emplace_back(i);
   			continue;
   		}
   		if (s[i] == '0') {
   			c0[i]++;
   			sum += c1[i] * y;
   		}else {
   			c1[i]++;
   			sum += c0[i] * x;
   		}
   	}

   	all_c0 = c0[n - 1], all_c1 = c1[n - 1];

   	int cnt_1 = sz(a);

   	int tmp = 0;
   	for(int i : a) {
   		tmp += (c0[i]) * x + (all_c0 - c0[i]) * y;
   	}

   	//cout << tmp << endl;

   	int res = tmp;

   	for(int i : a) {
   		cnt_1--;
   		tmp -= (c0[i]) * x + (all_c0 - c0[i]) * y;
   		tmp += c1[i] * y + (all_c1 - c1[i]) * x;
   		tmp -= (sz(a) - cnt_1 - 1) * x;
   		tmp += cnt_1 * x;

   		int new_res = tmp;
   		//cout << tmp << " " << new_res << endl;
   		chkmin(res, new_res);
   	}
   	cout << res + sum << endl;
}