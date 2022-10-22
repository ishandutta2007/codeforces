#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, q, p1[mxN+1], p2[mxN+1], prv1[mxN+1], prv2[mxN+1];
string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t >> q;
	int n=s.size(), m=t.size();
	for (int i=0; i<n; ++i) {
		p1[i+1]=p1[i]+(s[i]!='A');
		prv1[i+1]=s[i]=='A'?1+prv1[i]:0;
	}
	for (int i=0; i<m; ++i) {
		p2[i+1]=p2[i]+(t[i]!='A');
		prv2[i+1]=t[i]=='A'?1+prv2[i]:0;
	}
	while(q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d, --a, --b, --c, --d;
		int cnt1=p1[b+1]-p1[a];
		int cnt2=p2[d+1]-p2[c];
		int a1=min(b-a+1, prv1[b+1]);
		int a2=min(d-c+1, prv2[d+1]);
		if (cnt1>cnt2||(cnt2-cnt1)%2||a1<a2) {
			cout << 0;
			continue;
		}
		int need=(cnt2-cnt1)/2;
		if (a1==a2&&!cnt1&&need||!need&&(a1-a2)%3) {
			cout << 0;
			continue;
		}
		cout << 1;
	}
	return 0;
}