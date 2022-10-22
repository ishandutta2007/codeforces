#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, len[mxN][2], p[mxN+1], cnt[mxN];
string s;
vector<int> oc[mxN];

int find(int i) {
	return i^p[i]?p[i]=find(p[i]):i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	iota(p, p+n+1, 0);
	for (int i=n-1; ~i; --i)
		for (int j : {0, 1}) {
			len[i][j]=(s[i]!='0'+(j^1))?1+(i<n-1?len[i+1][j]:0):0;
			if (len[i][j]<n)
				oc[len[i][j]].push_back(i);
		}
	for (int i=1; i<=n; ++i) {
		for (int j : oc[i-1])
			if (++cnt[j]==2)
				p[j]=find(j+1);
		int ans=0;
		for (int j=find(0); j<n; j=find(j)) {
			assert(max(len[j][0], len[j][1])>=i);
			++ans;
			j+=i;
		}
		cout << ans << " ";
	}
	return 0;
}