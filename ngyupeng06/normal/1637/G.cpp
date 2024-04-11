#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, tc, hi[21], ch;
ll cap[50005];
vector<pll> ans;

vector<ll> solve(ll a, ll b){
	vector<ll> v;
	ll c = hi[cap[a]];
	for (int i=0; i<=c; i++){
		if (i >= 1 && i <= a) v.pb(1);
		else v.pb(0);
	}
	if (a <= 2) return v;
	ll cnt = 0;
	//cout << c << "\n";
	for (int i=c/2+1; i<=min(a,c-1); i++){
		cnt++;
		ans.pb(mp(i*b, (c-i)*b));
		v[i]--, v[c-i]--, v[c]++, v[2*i-c]++;
	}
	ll x = c/2 - cnt - 1;
	if (x > 0){
		for (int i=1; i<=x; i++) v[i]--;
		vector<ll> tmp = solve(x, b);
		for (int j=0; j<tmp.size(); j++){
	//		cout << tmp[j] << "TT\n";
			v[j] += tmp[j];
		}
	}
	for (int i=1; i<=cnt; i++){
		v[i*2]--;
	}
	vector<ll> tmp = solve(cnt, b*2);
	for (int j=0; j<tmp.size(); j++){
		v[2*j] += tmp[j];
	}
//	for (int i=0; i<v.size(); i++){
//		cout << i << " " << v[i] << "\n";
//	}
	if (a != ch) return v;
	vector<ll> th;
	bool ch1 = false;
	th.pb(0);
	for (int i=0; i<v.size(); i++){
	//	cout << i << " " << v[i] << "\n";
		if (!ch1 && v[i] >= 2){
			ch1 = true;
			ans.pb(mp(i,i));
			v[i] -= 2;
			v[2*i]++, v[0]++;
		}
		if (v[i]){
			for (int j=0; j<v[i]; j++){
				th.pb(i);
			}
		}
	}
//	for (auto it : th) cout << it << " ";
//	cout << '\n';
//	return v;
	while (th.back() != 0){
		while (!th.empty() && th.back() == c) th.pop_back();
		ll sz = th.size();
		if (sz == 1 || th.back() == 0) break;
		ll bb = th[sz-1], aa = th[sz-2];
		while (bb < c){
			ans.pb(mp(bb, aa));
			ans.pb(mp(bb+aa, bb-aa));
			bb *= 2;
			aa *= 2;
		}
		th.pop_back();
		th[sz-2] = aa;
	}
	ll sz = th.size();
	for (int i=0; i<sz; i++){
		ans.pb(mp(0, c));
	}
	return v;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	hi[0] = 1;
	for (int i=1; i<=20; i++){
		hi[i] = hi[i-1] * 2;
	}
	ll cur = 0;
	for (int i=0; i<50005; i++){
		if (hi[cur] < i) cur++;
		cap[i] = cur;
	}
	while (tc--){
		cin >> n;
		if (n == 2){
			cout << "-1\n";
			continue;
		}
		ans.clear();
		ch = n;
		solve(n, 1);
		cout << ans.size() << '\n';
		for (auto it : ans){
			cout << it.first << " " << it.second << "\n";
		}
	}
}