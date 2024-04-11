#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100001;
int n, q, c, a[mxN], prv[mxN], nxt[mxN][17];
set<int> p[mxN], cur;

bool bad(int x) {
	for (const int& i : p[x])
		if (cur.find(i)!=cur.end())
			return 1;
	return 0;
}

void add(int x) {
	for (const int& i : p[x])
		cur.insert(i);
}

void rem(int x) {
	for (const int& i : p[x])
		cur.erase(i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
	for (int i=2; i<mxN; ++i)
		if (p[i].empty())
			for (int j=i; j<mxN; j+=i)
				p[j].insert(i);
	for (int l=1, r=1; r<=n; ++r) {
		while(bad(a[r]))
			rem(a[l++]);
		add(a[r]);
		nxt[r][0]=l-1;
		for (int i=1; i<17; ++i)
			nxt[r][i]=nxt[nxt[r][i-1]][i-1];
	}
	while(q--) {
		int l, r, ans=1;
		cin >> l >> r;
		for (int i=16; ~i; --i)
			if (nxt[r][i]>=l)
				ans+=1<<i, r=nxt[r][i];
		cout << ans << "\n";
	}
	return 0;
}