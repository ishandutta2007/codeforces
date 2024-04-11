#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, ans[10001];
int qry(int i, int j) {
	assert(i>=1&&j>=1&&i<=n&&j<=n);
	cout << "? " << i << " " << j << endl;
	int x; cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if (n==1) {
		cout << "! 1" << endl;
		return 0;
	}
	fill(ans+1, ans+n+1, -1);
	int last=1;
	for (int i=2; i<=n; ++i) {
		int x=qry(last, i); //p[last]%p[i]
		int y=qry(i, last); //p[i]%p[last]
		if (x>y) {
			//last is smaller
			ans[last]=x;
			last=i;
		}
		else {
			assert(y>x); //cant be equality
			ans[i]=y;
		}
	}
	ans[last]=n;
	cout << "! ";
	for (int i=1; i<=n; ++i) {
		assert(ans[i]!=-1);
		if (i>1) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}