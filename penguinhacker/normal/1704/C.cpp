#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(m);
		for (int& i : a)
			cin >> i, --i;
		sort(a.begin(), a.end());
		vector<int> v;
		for (int i=0; i<m; ++i) {
			int nxt=i<m-1?a[i+1]:a[0]+n;
			v.push_back(nxt-a[i]-1);
		}
		sort(v.rbegin(), v.rend());
		int ans=0, sub=0;
		for (int i : v) {
			//cout << i << endl;
			i-=sub;
			if (i<=0)
				break;
			ans+=max(1, i-1);
			sub+=4;
		}
		cout << n-ans << "\n";
	}
	return 0;
}