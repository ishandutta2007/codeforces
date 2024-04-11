#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n2=1, c[mxN*30][2];
ll ans;

vector<int> solve(vector<int> a, int b) {
	if (a.size()<=1||b==-1)
		return a;
	vector<int> x, y;
	for (int i : a) {
		if (i&1<<b)
			y.push_back(i);
		else
			x.push_back(i);
	}
	x=solve(x, b-1);
	y=solve(y, b-1);
	if (x.empty()||y.empty())
		return x.size()?x:y;
	int mn=2e9;
	for (int i : x.size()<y.size()?x:y) {
		i^=1<<b;
		int cur=0, u=0;
		for (int j=29; ~j; --j) {
			int bit=i>>j&1;
			if (c[u][bit])
				u=c[u][bit];
			else {
				assert(c[u][bit^1]);
				cur+=1<<j;
				u=c[u][bit^1];
			}
		}
		mn=min(mn, cur);
	}
	ans+=mn+(1<<b);
	x.insert(x.end(), y.begin(), y.end());
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) {
		cin >> i;
		int u=0;
		for (int j=29; ~j; --j) {
			int bit=i>>j&1;
			if (!c[u][bit])
				c[u][bit]=n2++;
			u=c[u][bit];
		}
	}
	solve(a, 29);
	cout << ans;
	return 0;
}