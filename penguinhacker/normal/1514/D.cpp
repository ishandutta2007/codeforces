#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const unsigned long long SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

int rand(int l, int r) {
	return l+rng()%(r-l+1);
}

const int mxN=300000, B=30;
int n, q, a[mxN], cnt[mxN], ql[mxN], qr[mxN], c[mxN*B], e[mxN*B];
vector<ar<int, 3>> qry[mxN];
vector<int> lq[mxN], rq[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	for (int i=0; i<q; ++i) {
		cin >> ql[i] >> qr[i], --ql[i], --qr[i];
		if (ql[i])
			lq[ql[i]-1].push_back(i);
		rq[qr[i]].push_back(i);
		for (int j=0; j<B; ++j)
			e[i*B+j]=a[rand(ql[i], qr[i])];
	}
	for (int i=0; i<n; ++i) {
		++cnt[a[i]];
		for (int j : lq[i])
			for (int k=0; k<B; ++k)
				c[j*B+k]-=cnt[e[j*B+k]];
		for (int j : rq[i])
			for (int k=0; k<B; ++k)
				c[j*B+k]+=cnt[e[j*B+k]];
	}
	for (int i=0; i<q; ++i) {
		int mx=0;
		int len=qr[i]-ql[i]+1;
		int ce=(len+1)/2;
		for (int j=0; j<B; ++j)
			mx=max(mx, c[B*i+j]);
		if (mx<=ce) {
			cout << "1\n";
			continue;
		}
		cout << 1+(mx-(len-mx+1)) << "\n";
	}
	return 0;
}