#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#define debug(x) cerr << "[" << #x << "] = [" << x << "]\n"

template<class T> ostream& operator<< (ostream& out, vector<T> v) {
	out << '[';
	for (int i = 0; i < v.size(); ++i) {
		if (i > 0) {
			out << ", ";
		}
		out << v[i];
	}
	return out << ']';
}

template<class T> ostream& operator<< (ostream& out, multiset<T> v) {
	return out << vector<T>(v.begin(), v.end());
}

const int mxN=1e5;
int n, k, a[mxN];
bool seen[mxN+5];

void solve() {
	cin >> n >> k;
	map<int, int> mp;
	for (int i=0; i<n; ++i)
		seen[i]=0;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		++mp[a[i]];
		if (a[i]<=n+1)
			seen[a[i]]=1;
	}

	int need=0;
	for (int i=0; i<n; ++i)
		need+=!seen[i];

	int sum=0;
	multiset<int> use, usel;

	auto Norm=[&]() {
		while(1) {
			//debug(use);
			//debug(usel);
			if (usel.size()&&*usel.begin()+sum<=k) {
				use.insert(*usel.begin());
				sum+=*usel.begin();
				usel.erase(usel.begin());
			} else if (use.size()&&usel.size()&&*usel.begin()<*use.rbegin()) {
				int a=*usel.begin(), b=*use.rbegin();
				usel.erase(usel.begin()), use.erase(--use.end());
				sum+=a-b;
				use.insert(a), usel.insert(b);
			} else
				break;
		}
	};

	for (auto x : mp)
		if (x.first>n)
			usel.insert(x.second);

	int ans=1e9;
	for (int mex=n; ~mex; --mex) {
		if (mp.find(mex)!=mp.end())
			usel.insert(mp[mex]);
		if (mex<n&&!seen[mex])
			--need;
		if (need<=k) {
			Norm();
			ans=min(ans, (int)usel.size());
		}
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