#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll m, s=0, ans=0;
vector<int> v;

void reduce() {
	vector<int> temp;
	for (int i : v) {
		if (m>=i)
			temp.push_back(i);
		else
			s-=i;
	}
	v=temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	v.resize(n);
	for (int i=0; i<n; ++i)
		cin >> v[i], s+=v[i];
	while(!v.empty()) {
		n=v.size();
		ans+=(m/s)*n;
		m%=s;
		for (int i : v) {
			if (m>=i) {
				m-=i;
				++ans;
			}
		}
		reduce();
	}
	cout << ans;
	return 0;
}