#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 85 - 69;
string s;
int z[maxn], zz[maxn];
int n, L, R;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();
	for(int i = 1; i < n; i++){
		if(i > R){
			L = i, R = i - 1;
			while(R + 1 < n and s[R + 1] == s[R - L + 1]) R++;
			z[i] = R - L + 1;
		}
		else{
			int k = i - L;
			if(z[k] <= R - i)
				z[i] = z[k];
			else{
				L = i;
				while(R + 1 < n and s[R + 1] == s[R - L + 1]) R++;
				z[i] = R - L + 1;
			}
		}
		zz[i] = z[i];
	}
	z[0] = zz[0] = n;
	sort(zz, zz + n);
	vector<pair<int, int> > ans;
	for(int i = n - 1; i >= 0; i--){
		if(z[i] == n - i){
			int cnt = lower_bound(zz, zz + n, n - i) - zz;
			ans.push_back(make_pair(n - i, n - cnt));
		}
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	return 0;
}