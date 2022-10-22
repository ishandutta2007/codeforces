#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=1e9+696969, B=53;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, nxt[mxN][26];
string s;
ll h[mxN+1][26], p[mxN];

vector<ar<int, 2>> g1(int l, int r) {
	assert(0<=l&&l<=r&&r<n);
	vector<ar<int, 2>> a;
	for (int i=0; i<26; ++i)
		if (nxt[l][i]!=-1&&nxt[l][i]<=r)
			a.push_back({nxt[l][i], i});
	sort(a.begin(), a.end());
	return a;
}

ll g2(int l, int r, int i) {
	return (h[r+1][i]-h[l][i]*p[r-l+1]%M+M)%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	memset(nxt[n-1], -1, sizeof(nxt[n-1]));
	nxt[n-1][s[n-1]-'a']=n-1;
	for (int i=n-2; ~i; --i) {
		memcpy(nxt[i], nxt[i+1], sizeof(nxt[i]));
		nxt[i][s[i]-'a']=i;
	}
	for (int i=0; i<n; ++i)
		for (int j=0; j<26; ++j)
			h[i+1][j]=(B*h[i][j]+(s[i]-'a'==j))%M;
	p[0]=1;
	for (int i=1; i<n; ++i)
		p[i]=p[i-1]*B%M;
	while(m--) {
		int x, y, len;
		cin >> x >> y >> len, --x, --y;
		vector<ar<int, 2>> a=g1(x, x+len-1), b=g1(y, y+len-1);
		bool ok=a.size()==b.size();
		for (int i=0; i<a.size()&&ok; ++i)
			ok&=a[i][0]-x==b[i][0]-y;
		if (!ok) {
			cout << "NO\n";
			continue;
		}
		ll h1=0, h2=0;
		for (int i=0; i<a.size(); ++i) {
			ll mult=rng()%M;
			h1=(h1+g2(x, x+len-1, a[i][1])*mult)%M;
			h2=(h2+g2(y, y+len-1, b[i][1])*mult)%M;
		}
		cout << (h1==h2?"YES":"NO") << "\n";
	}
	return 0;
}