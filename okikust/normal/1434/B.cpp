#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int n;
	char a[5];
	stack<int>st;
	int b[(2 * N)];
	int c[(2 * N)];
	priority_queue<int>pq;
	int d[N];
	int k, x, y, z;
	bool v = true;
	k = 0;
	x = 0;
	cin >> n;
	rep(i, 2 * n) {
		rep(j, 5)a[j] = 0;
		cin >> a;
		if (a[0] == '-') {
			cin >> c[i];
			b[i] = -1;
			if (st.empty())v = false;
			else {
				x = st.top();
				d[x] = c[i];
				st.pop();
			}
		}
		else {
			b[i] = k;
			st.push(k);
			k++;
		}
	}
	if (!v) {
		cout << "NO" << endl;
		return 0;
	}
	rep(i, 2 * n) {
		if (b[i] >= 0) {
			pq.push(-d[b[i]]);
		}
		else {
			x = pq.top();
			x = -x;
			pq.pop();
			if (x != c[i])v = false;
		}
	}
	if (v) {
		cout << "YES" << endl;
		rep(i, n - 1)cout << d[i] << " ";
		cout << d[n - 1] << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}