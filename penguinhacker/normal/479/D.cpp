#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, l, x, y, a[100000];
set<int> marks;
bool b=0, g=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> x >> y;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		marks.insert(a[i]);
	}
	for (int i=0; i<n-1; ++i) {
		if (marks.find(a[i]+x)!=marks.end())
			g=1;
		if (marks.find(a[i]+y)!=marks.end())
			b=1;
	}
	if (g&&b)
		cout << 0;
	else if (g)
		cout << 1 << '\n' << y;
	else if (b)
		cout << 1 << '\n' << x;
	else {
		set<int> posB, posG;
		for (int i=0; i<n; ++i) {
			if (0<=a[i]-x)
				posG.insert(a[i]-x);
			if (a[i]+x<=l)
				posG.insert(a[i]+x);
			if (0<=a[i]-y)
				posB.insert(a[i]-y);
			if (a[i]+y<=l)
				posB.insert(a[i]+y);
		}
		for (const int &i:posB) {
			if (posG.find(i)!=posG.end()) {
				cout << 1 << '\n' << i;
				return 0;
			}
		}
		cout << 2 << '\n' << x << ' ' << y;
	}
	return 0;
}