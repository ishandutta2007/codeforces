#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[500];
vector<int> ans;

bool shift(int i) {
	int x=a[i], y=a[i+1], z=a[i+2];
	a[i]=z, a[i+1]=x, a[i+2]=y;
	ans.push_back(i);
	int bef=(x>y)+(x>z)+(y>z);
	int aft=(a[i]>a[i+1])+(a[i]>a[i+2])+(a[i+1]>a[i+2]);
	return abs(bef-aft)%2;
}

bool norm() {
	map<int, vector<int>> oc;
	vector<int> inds(n);
	int inv=0;
	for (int i=0; i<n; ++i) {
		inds[i]=i;
		oc[a[i]].push_back(i);
		for (int j=i+1; j<n; ++j)
			inv+=a[i]>a[j];
	}
	if (inv%2&&oc.size()==n)
		return 0;
	if (inv%2) {
		int i1, i2;
		for (auto& x : oc)
			if (x.second.size()>=2)
				i1=x.second[0], i2=x.second[1];
		bool ok=0;
		while(!ok&&i2-i1>2)
			ok|=shift(i1++);
		if (!ok)
			for (int i=0; i<n; ++i) {
				int x=a[i]!=a[i+1], y=a[i]!=a[i+2], z=a[i+1]!=a[i+2];
				if (x+y+z==2) {
					while(!ok)
						ok|=shift(i);
					break;
				}
			}
		assert(ok);
	}
	sort(inds.begin(), inds.end(), [&](int x, int y) {return a[x]^a[y]?a[x]<a[y]:x<y;});
	for (int i=0; i<n; ++i)
		a[inds[i]]=i;
	return 1;
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	if (!norm()) {
		cout << "-1\n";
		return;
	}
	for (int i=n-1; i>=2; --i) {
		int mx=i;
		for (int j=i-1; ~j; --j)
			if (a[j]>a[mx])
				mx=j;
		if (mx==i)
			continue;
		while(mx+2<=i) {
			shift(mx);
			++mx;
		}
		shift(i-2);
	}
	for (int i=0; i<2&&a[0]>a[1]||a[1]>a[2]; ++i)
		shift(0);
	assert(a[0]<a[1]&&a[1]<a[2]);
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i+1 << " ";
	cout << "\n";
	ans.clear();
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