#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;
 
int n;
vector<int> a, sorted, res;

void f(int id) {
	res.emplace_back(id + 1);
	swap(a[id], a[id + 1]);
	swap(a[id], a[id + 2]);
}

void pref(int beg) {
	int id = 0;
	for(int i = beg;i < n;i++) if (a[i] == sorted[beg]) id = i;

	while(id != beg) {
		if (id == beg + 1) {
			id++;
			f(beg);
		}else{
			id -= 2;
			f(id);
		}
	}
}

void suf(int last) {
	int id = 0;
	for(int i = 0;i <= last;i++) if (a[i] == sorted[last]) id = i;

	while(id != last) {
		if (id == last - 1) f(id - 1);
		else f(id);
		id++;
	}
	//cout << last << endl;
}



void solve() {
	a.clear();
	sorted.clear();
	res.clear();

	cin >> n;

	a.resize(n);
	for(int i =0;i < n;i++) {
		cin >> a[i];
		sorted.emplace_back(a[i]);
	}

	sort(sorted.begin(), sorted.end());

	int last_id = a.size() - 2;

	for(int i =0;i < a.size() - 1;i++) if (sorted[i] == sorted[i + 1]) last_id = i;

	for(int i = 0;i < last_id;i++) pref(i);

	/*for(int i : a) cout << i << " ";
	cout << endl;*/

	for(int i = n - 1;i >= last_id + 2;i--) suf(i);

	if (a[n - 1] < a[n - 2]) cout << -1 << endl;
	else{
		cout << res.size() << endl;
		for(int i : res) cout << i << " ";
		cout << endl;
	}
}


signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
    	solve();
    }
}