#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string ans=string(n-1, 'U')+string(m-1, 'L');
	for (int i=0; i<n; ++i) {
		ans+=string(m-1, i%2?'L':'R');
		if (i+1<n)
			ans+='D';
	}
	cout << ans.size() << "\n" << ans;
	return 0;
}