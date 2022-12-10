#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define endl '\n'

const int maxn = 4e6 + 85 - 69;
int cnt[maxn], l[maxn], r[maxn];
int n, k;
vector<int> all, sef;
vector<pii> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		all.PB(l[i]), all.PB(r[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n; i++){
		int idl = lower_bound(all.begin(), all.end(), l[i]) - all.begin(),
			idr = lower_bound(all.begin(), all.end(), r[i]) - all.begin();
		cnt[idl * 2]++;
		cnt[idr * 2 + 1]--;
	}
	for(int i = 1; i < sz(all) * 2; i++)
		cnt[i] += cnt[i - 1];
	for(int i = 0; i < sz(all) * 2;){
		if(cnt[i] < k){
			i++;
			continue;
		}
		int p = i;
		while(p < sz(all) * 2 and cnt[p] >= k) p++;
		ans.PB(MP(all[i / 2], all[p / 2]));
		i = p;
	}
	cout << sz(ans) << endl;
	for(auto p : ans)
		cout << p.L << ' ' << p.R << endl;
	return 0;
}