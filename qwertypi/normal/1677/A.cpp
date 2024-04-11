#include <bits/stdc++.h>

using namespace std;

int A[5001];
int l[5001], r[5001], sl[5001], sr[5001];

const int N = 5000;
struct BIT{
	int bit[5002];
	void upd(int p, int v){
		for(int i = p; i <= N; i += i & -i){
			bit[i] += v; 
		}
	}
	int qry(int p){
		int ret = 0;
		for(int i = p; i; i -= i & -i){
			ret += bit[i];
		}
		return ret;
	}
} bit1, bit2;

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	long long ans = 0;
	for(int i = 0; i < n; i++){
		fill(bit1.bit, bit1.bit + N + 1, 0);
		fill(bit2.bit, bit2.bit + N + 1, 0);
		for(int j = i + 1; j < n; j++) bit2.upd(A[j], 1);
		int cur = 0;
		for(int j = i + 1; j < n; j++){
			cur -= bit1.qry(N) - bit1.qry(A[j]);
			bit2.upd(A[j], -1);
			if(A[i] < A[j]){
				ans += cur;
			}
			cur += bit2.qry(A[j] - 1);
			bit1.upd(A[j], 1);
		}
	}
	cout << ans << endl;
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}