//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define hash HasH

const int maxn = 100 * 1000;
const LL Mod = 10022390619214807,
	  base = 313;
int n, ans;
LL P[maxn],
   hash[maxn];
vector<int> vecans[maxn];
vector<string> hosts,
	paths;
string s[maxn],
	   host[maxn],
	   path[maxn];
set<pll> se;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = base;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);
	n = unique(s, s + n) - s;
	for(int i = 0; i < n; i++){
		int it = find(s[i].begin() + 7, s[i].end(), '/') - s[i].begin();
		host[i] = s[i].substr(7, it - 7);
		path[i] = s[i].substr(it, sz(s[i]) - it);
		paths.PB(path[i]);
		hosts.PB(host[i]);
	}
	sort(all(paths));
	sort(all(hosts));
	paths.resize(unique(all(paths)) - paths.begin());
	hosts.resize(unique(all(hosts)) - hosts.begin());
	for(int i = 0; i < n; i++){
		int hostid = lower_bound(all(hosts), host[i]) - hosts.begin(),
			pathid = lower_bound(all(paths), path[i]) - paths.begin();
		hash[hostid] = (hash[hostid] + P[pathid]) % Mod;
	}
	for(int i = 0; i < sz(hosts); i++)
		se.insert(MP(hash[i], i));
	for(auto it = se.begin(); it != se.end();){
		auto it2 = it;
		int cnt = 0;
		while(it2 != se.end() and it2->L == it->L) it2++, cnt++;
		if(cnt > 1){
			while(it != it2)
				vecans[ans].PB(it->R), it++;
			ans++;
		}
		else it++;
	}
	cout << ans << '\n';
	for(int i = 0; i < ans; i++, cout << '\n')
		for(auto id : vecans[i])
			cout << "http://" << hosts[id] << ' ';
	return 0;
}