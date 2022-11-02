#include <bits/stdc++.h>

// nothing to say
using namespace std;

int a[200003];
int cnt[200003], s[200003];
int c2[200003], s2[200003];

#define MAXN 200004
// doesn't give me IOI at least give me some rating
struct BIT{
	int bit[MAXN];
	void upd(int p, int v){
		p++;
		for(int i = p; i < MAXN; i += i & -i){
			bit[i] += v;
		}
	}
	int qry(int p){
		p++;
		int ret = 0;
		for(int i = p; i; i -= i & -i){
			ret += bit[i];
		}
		return ret;
	}
	int bs(int s){
		int ret = 0, res = 0;
		for(int j = 19; j >= 0; j--){
			if(ret + (1 << j) < MAXN && res + bit[ret + (1 << j)] <= s) res += bit[ret + (1 << j)], ret += (1 << j); 
		}
		ret--;
		return ret;
	}
} bit1, bit2;

int check(int rem){
	if(rem < 0) return -(1 << 30);
	int r = bit1.bs(rem);
	int cnt = bit2.qry(r);
	int a0 = rem - bit1.qry(r);
	if(r + 1 != MAXN) cnt += a0 / (r + 1);
	return cnt;
}

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i <= n; i++) cnt[i] = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	map<int, int> M;
	for(int i = 0; i < n; i++){
		M[a[i]]++;
		a[i] = min(a[i], n);
		cnt[a[i]] = true;
	}
	vector<pair<int, int>> vp;
	for(auto i : M) vp.push_back(i); int idx = M.size() - 1;
	for(int i = 0; i <= n; i++) s[i + 1] = s[i] + cnt[i];
	int ans = n;
	for(int mex = n; mex >= 0; mex--){
		while(idx >= 0 && vp[idx].first >= mex) bit1.upd(vp[idx].second, vp[idx].second), bit2.upd(vp[idx].second, 1), idx--;
		int k_need = mex - s[mex];
		// cout << k_need << endl;
		if(k < k_need) continue;
		int res = M.size() - s[mex] - check(k);
		// cout << n << ' ' << mex << ' ' << check(k) << endl;
		ans = min(ans, res);
	}
	for(auto i : vp){
		bit1.upd(i.second, -i.second), bit2.upd(i.second, -1);
	}
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}