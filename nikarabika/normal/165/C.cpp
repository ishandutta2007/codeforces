#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll ans;

int main(){
	ios_base::sync_with_stdio(false);
	int k;
	string s;
	cin >> k >> s;
	int sz[s.size() + 1];
	sz[0] = 0;
	for(int i = 1; i <= s.size(); i++)
		sz[i] = sz[i - 1] + s[i - 1] - '0';
	for(int i = 0; i <= s.size(); i++){
		ll p1 = lower_bound(sz, sz + s.size() + 1, sz[i] + k) - sz,
			p2 = upper_bound(sz, sz + s.size() + 1, sz[i] + k) - sz;
		ans += p2 - p1;
		if(k == 0)
			ans --;
	}
	if(k == 0)
		cout << ans/2 << endl;
	else
		cout << ans << endl;
	return 0;
}