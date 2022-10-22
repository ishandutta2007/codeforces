#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

char q1(int i) {
	cout << "? 1 " << i+1 << endl;
	char c;
	cin >> c;
	return c;
}

int q2(int l, int r) {
	cout << "? 2 " << l+1 << " " << r+1 << endl;
	int x;
	cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, char>> oc;
	oc.push_back({0, q1(0)});
	string ans;
	ans+=oc[0].second;
	vector<vector<pair<int, char>>> d(n);
	d[0]=oc;
	for (int i=1; i<n; ++i) {
		if (q2(0, i)>oc.size()) {
			oc.push_back({i, q1(i)});
			ans+=oc.back().second;
		} else {
			int lb=0, rb=d[i-1].size()-1;
			while(lb<rb) {
				int mid=(lb+rb)/2;
				if (q2(d[i-1][mid].first, i)==mid+1)
					rb=mid;
				else
					lb=mid+1;
			}
			ans+=d[i-1][lb].second;
		}
		vector<bool> seen(26);
		int cur=0;
		for (int j=i; ~j; --j) {
			if (!seen[ans[j]-'a']) {
				seen[ans[j]-'a']=1;
				d[i].push_back({j, ans[j]});
			}
		}
	}
	cout << "! " << ans << endl;
	return 0;
}