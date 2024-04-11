#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[300001];
int lp[1000001];
int cnt[1000001];

int p[1001];
int idx = 0;
void prec(){
	for(int i = 2; i <= 1000; i++){
		bool fail = false;
		for(int j = 0; j < idx; j++){
			if(i % p[j] == 0) {
				fail = true;
				break;
			}
		}
		if(!fail) p[idx++] = i;
	}
	p[idx++] = 1001;
}

void solve(){
	// cout << "solve" << endl;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		int v = 1;
		for(int j = 0; p[j] * p[j] <= A[i]; j++){
			while(A[i] % (p[j] * p[j]) == 0) A[i] /= p[j] * p[j];
		}
	}
	
	for(int i = 0; i < n; i++){
		cnt[A[i]] = 0;
	}
	int ans0 = 0, ans1 = 0;
	for(int i = 0; i < n; i++){
		cnt[A[i]]++;
	}
	for(int i = 0; i < n; i++){
		ans0 = max(ans0, cnt[A[i]]);
	}
	for(int i = 0; i < n; i++){
		if(cnt[A[i]] % 2 == 0){
			A[i] = 1;
		}
	}
	for(int i = 0; i < n; i++){
		if(A[i] == 1) ans1++;
	}
	ans1 = max(ans0, ans1);
	cerr << ans0 << ' ' << ans1 << '\n'; 
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int v; cin >> v;
		cout << (v == 0 ? ans0 : ans1) << '\n';
	}
}

int32_t main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false); 
	prec();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}