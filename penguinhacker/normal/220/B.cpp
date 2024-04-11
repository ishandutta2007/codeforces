#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000, BLOCK=400;
struct QRY {
	int l, r, ind;
	bool operator<(const QRY &o) const {return l/BLOCK!=o.l/BLOCK?l/BLOCK<o.l/BLOCK:r<o.r;}
} q[mxN];

int n, m, a[mxN], cnt[mxN+1];
int ans[mxN], curAns=0;

void op(int i, int inc) {
	if (a[i]>n) return;
	if (cnt[a[i]]==a[i]) --curAns;
	cnt[a[i]]+=inc;
	if (cnt[a[i]]==a[i]) ++curAns;
}

void process() {
	sort(q, q+m);
	for (int i=0, lb=0, rb=0; i<m; ++i) {
		int l=q[i].l, r=q[i].r;
		while(lb>l) op(--lb, 1);
		while(rb<r+1) op(rb++, 1);
		while(lb<l) op(lb++, -1);
		while(rb>r+1) op(--rb, -1);
		ans[q[i].ind]=curAns;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		q[i]={a, b, i};
	}
	process();
	for (int i=0; i<m; ++i)
		cout << ans[i] << "\n";
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/