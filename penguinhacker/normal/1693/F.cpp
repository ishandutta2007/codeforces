#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	string s;
	cin >> n >> s;
	if (count(s.begin(), s.end(), '1')>count(s.begin(), s.end(), '0')) {
		reverse(s.begin(), s.end());
		for (char& c : s)
			c='0'+(c=='0');
	}
	vector<bool> suf_good(n);
	for (int i=n-1; ~i; --i)
		suf_good[i]=(s[i]=='1')&&(i+1<n?suf_good[i+1]:1);
	bool ok=1;
	for (int i=n-1; ~i; --i)
		ok&=suf_good[i]||s[i]=='0';
	if (ok) {
		cout << "0\n";
		return;
	}

	map<int, vector<int>> oc;
	oc[0].push_back(n);
	vector<int> depth(n+1);
	for (int i=n-1; ~i; --i) {
		depth[i]=depth[i+1]+(s[i]=='1'?1:-1);
		oc[depth[i]].push_back(i);
	}

	int tot1=count(s.begin(), s.end(), '1');
	int i=find(s.begin(), s.end(), '1')-s.begin();
	int bal=1;
	int cnt1=1;
	int j=i+1;
	int ans=0;
	while(1) {
		// starting position is i
		if (tot1>=n-i) {
			assert(cnt1==n-i);
			break;
		}
		if (tot1*2>=n-i) {
			++ans;
			break;
		}
		++ans;
		while(1) { // extend seg rightwards
			while(j<n&&bal>0) {
				bal+=s[j]=='1'?1:-1;
				cnt1+=s[j]=='1';
				++j;
			}
			while(oc[depth[j]].size()&&oc[depth[j]].back()<=j)
				oc[depth[j]].pop_back();
			if (oc[depth[j]].empty())
				break;
			int nj=oc[depth[j]].back();
			while(j<nj) {
				bal+=s[j]=='1'?1:-1;
				cnt1+=s[j]=='1';
				++j;
			}
			assert(bal==0);
		}
		//cout << i << " " << j << endl;
		assert(bal==0&&j<n);
		// sort seg [i, j]
		assert((j-i)%2==0&&2*cnt1==(j-i));
		i+=cnt1, bal+=cnt1;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}