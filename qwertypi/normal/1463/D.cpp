#include <bits/stdc++.h>

using namespace std;

int A[200001];
int B[200001];
int n;
struct segtree{
	int t[1600001];
	int ps[1600001], ss[1600001], s[1600001], m[1600001];
	void init(int n){
		fill(t, t + n * 8, 0);
		fill(ps, ps + n * 8, 0);
		fill(ss, ss + n * 8, 0);
		fill(s, s + n * 8, 0);
	}
	void merge(int t){
		ps[t] = min(ps[t << 1], s[t << 1] + ps[t << 1 | 1]);
		ss[t] = min(ss[t << 1 | 1], s[t << 1 | 1] + ss[t << 1]);
		s[t] = s[t << 1] + s[t << 1 | 1];
		m[t] = min(min(m[t << 1], m[t << 1 | 1]), ss[t << 1] + ps[t << 1 | 1]);
	}
	
	void upd(int p, int v, int t = 1, int tl = 0, int tr = n * 2 - 1){
		if(tl == tr){
			s[t] = v;
			ps[t] = ss[t] = min(0, v);
			return;
		}
		int tm = (tl + tr) >> 1;
		if(p <= tm){
			upd(p, v, t << 1, tl, tm);
		}else{
			upd(p, v, t << 1 | 1, tm + 1, tr);
		}
		merge(t);
	}
	
	int qry(){
		return ps[1];
	}
} seg1, seg2;

void solve(){
	cin >> n;
	seg1.init(n);
	seg2.init(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int ai = 0, bi = 0;
	for(int i = 1; i <= n * 2; i++){
		if(A[ai] != i){
			B[bi++] = i;
		}else{
			ai++;
		}
	}
	/*
	for(int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
	
	for(int i = 0; i < n; i++){
		cout << B[i] << ' ';
	}
	cout << endl;
	*/
	for(int i = 0; i < n; i++){
		seg1.upd(A[i] - 1, 1);
		seg1.upd(B[i] - 1, -1);
	}
	// cout << seg1.qry() << ' ' << seg2.qry() << endl;
	int ans = 0;
	if(seg1.qry() >= 0){
		// cout << 0 << endl;
		ans++;
	}
	for(int i = 0; i < n; i++){
		seg1.upd(A[n - 1 - i] - 1, 0);
		seg2.upd(A[n - 1 - i] - 1, -1);
		seg1.upd(B[i] - 1, 0);
		seg2.upd(B[i] - 1, 1);
		// cout << seg1.qry() << ' ' << seg2.qry() << endl;
		if(seg1.qry() >= 0 && seg2.qry() >= 0){
			ans++;
			// cout << i + 1 << endl;
		}
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