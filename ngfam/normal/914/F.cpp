#include <bits/stdc++.h>

using namespace std;

string s, r;
bitset < 100010 > inf;
bitset < 100010 > ans;
bitset < 100010 > a[26];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> s;
	n = s.size();

	for(int i = 0; i < n; ++i){
		inf[i] = 1;
		a[s[i] - 'a'][i] = 1;
	}	


	int q;
	cin >> q;

	r = s;


	while(q--){
		int t;
		char c;

		cin >> t;
		if(t == 1){
			int p;
			cin >> p >> c;

			--p;
			a[r[p] - 'a'][p] = 0;

			r[p] = c;
			a[c - 'a'][p] = 1;
			continue;
		}

		int l, r;
		cin >> l >> r >> s;


		if(s.size() > r - l + 1){
			cout << 0 << '\n';
			continue;
		}

		--l; --r;
		ans = inf;

		for(int i = 0; i < s.size(); ++i){
			ans &= (a[s[i] - 'a'] >> (l + i));
		}

		cout << ans.count() - (ans >> (r - l - s.size() + 2)).count() << '\n';
	}


	return 0;
}