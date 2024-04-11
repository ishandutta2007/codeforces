#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef long long int ll;

const int maxn = 1e6 + 10;
vector<int> a, el, cnt;
int T[maxn * 4], dp[maxn], n;
ll ans;

void add(int val, int idx, int L = 0, int R = maxn, int id = 1){
	T[id] += val;
	if(R - L == 1)
		return;
	int mid = (L + R) >> 1;
	if(idx < mid)
		add(val, idx, L, mid, id * 2 + 0);
	else
		add(val, idx, mid, R, id * 2 + 1);
}

ll query(int l, int r, int L = 0, int R = maxn, int id = 1){
	if(l == L and r == R)
		return T[id];
	int mid = (L + R) >> 1;
	ll ret = 0;
	if(l < mid)
		ret += query(l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		ret += query(max(mid, l), r, mid, R, id * 2 + 1);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.PB(x);
		el.PB(x);
	}
	sort(el.begin(), el.end());
	el.resize(unique(el.begin(), el.end()) - el.begin());
	cnt.resize(el.size());	

	for(int i = 0; i < cnt.size(); i++)
		cnt[i] = 0;
	for(int i = a.size() - 1; i >= 0; i--)
		add(1, dp[i] = ++(*(lower_bound(el.begin(), el.end(), a[i]) - el.begin() + cnt.begin())));
	for(int i = 0; i < cnt.size(); i++)
		cnt[i] = 0;
	for(int i = 0; i < a.size(); i++){
		add(-1, dp[i]);
		int x = ++(*(lower_bound(el.begin(), el.end(), a[i]) - el.begin() + cnt.begin()));
		ans += 1LL * query(0, x);
	}
	cout << ans << endl;
	
	/*

	int ty, fi, se;
	while(cin >> ty >> fi >> se){
		if(ty == 1)
			add(se, fi - 1);
		else
			cout << query(fi - 1, se) << endl;
	}
	*/
	return 0;
}