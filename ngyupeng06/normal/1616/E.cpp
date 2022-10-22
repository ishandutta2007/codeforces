#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, q;

int ft[200005];

void update(int x, int v) {
	for (; x < 200005; x += x & -x) ft[x] += v;
}

int query(int x) {
	int sum = 0;
	for (; x; x -= x & -x) sum += ft[x];
	return sum;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> q;
	while (q--){
		string s, t;
		cin >> n >> s >> t;
		int ms = 100, mt = -1;
		queue<int> v[30];
		for (int i=0; i<=n+5; i++){
			ft[i] = 0;
		}
		for (int i=0; i<n; i++){
			int x = s[i] - 'a';
			int y = t[i] - 'a';
			ms = min(ms, s[i] - 'a');
			mt = max(mt, t[i] - 'a');
			v[x].push(i);
		}
		string s1 = s;
		sort(s1.begin(), s1.end());
		if (s1 >= t){
			cout << -1 << "\n";
			continue;
		}
		ll ans = 2e18;
		ll cur = 0;
		for (int i=0; i<n; i++){
			int x = t[i] - 'a';
			for (int j=0; j<x; j++){
				if (v[j].empty())continue;
				int y = v[j].front();
				ans = min(ans, cur + y - query(y));
			}
			if (!v[x].empty()){
				int pos = v[x].front();
				v[x].pop();
				int thing = pos - query(pos);
				cur += thing;
				update(pos+1, 1);
			}
			else {
				break;
			}
		}
		cout << ans << "\n";
	}
}