#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int


    
using namespace std;

const int MAXN = (int) 1e3;

int x[MAXN + 1], y[MAXN + 1];

inline ll ccw(int i, int j) {
	return 1LL * x[i] * y[j] - 1LL * x[j] * y[i];
}

inline ll get(int t, int i, int j, int k) {
	if(t == 1) {
		return llabs(ccw(i, j) + ccw(j, k) + ccw(k, i));
	}
	else {
		return ccw(i, j) + ccw(j, k) + ccw(k, i);
	}
}

inline ll ask(int t, int i, int j, int k) {
	if(i == j || j == k || i == k) return 0;

	cout << t << " " << i << " " << j << " " << k << endl;
	ll ans;
	cin >> ans;
	//ans = get(t, i, j, k);

	return ans;
}

inline vector <int> solve(int a, int b, vector <int> arr) {
	ll mx = 0;
	int c;
	
	vector <ll> area;
	for(auto it : arr) {
		ll cur = ask(1, a, it, b);
		area.push_back(cur);
		if(cur > mx) {
			mx = cur, c = it;
		}
	}

	vector < pair <ll, int> > x, y;
	int p = 0;

	for(auto it : arr) {
		if(ask(2, it, a, c) < 0) {
			x.push_back({area[p], it});
		}
		else {
			y.push_back({area[p], it});
		}
		p++;
	}

	sort(x.begin(), x.end());
	sort(y.rbegin(), y.rend());

	vector <int> ans;
	for(auto it : x) {
		ans.push_back(it.second);
	}
	for(auto it : y) {
		ans.push_back(it.second);
	}

	return ans;

}
  
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
	int i, n;
    //ios::sync_with_stdio(false);
   	//cin.tie(0), cout.tie(0);

	cin >> n;
	/*for(i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}*/

	vector <int> a, b;
	for(i = 3; i <= n; i++) {
		if(ask(2, 1, 2, i) < 0) {
			a.push_back(i);
		}
		else {
			b.push_back(i);
		}
	}

	auto A = solve(1, 2, a);
	auto B = solve(2, 1, b);

	cout << 0 << " " << 1 << " ";
	for(auto it : A) {
		cout << it << " ";
	}
	cout << 2 << " ";
	for(auto it : B) {
		cout << it << " ";
	}
	cout << endl;
		
	return 0;
}