#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, ans=0, cnt[2]={0, 0};
string s, t, st, tt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s >> t;
	if (count(s.begin(), s.end(), '1')!=count(t.begin(), t.end(), '1')) {
		cout << -1;
		return 0;
	}
	vector<int> v;
	for (int i=0; i<n; ++i)
		if (s[i]!=t[i])
			st.push_back(s[i]), tt.push_back(t[i]);
	s=st, t=tt;
	n=s.size();
	for (int i=0; i<s.size(); ++i) {
		int k=s[i]-'0';
		if (cnt[k]!=0) {
			--cnt[k];
			++cnt[k^1];
		}
		else {
			++ans;
			++cnt[k^1];
		}
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/