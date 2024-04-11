#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[500001];
int ex[500001];
int N;
struct BIT{
	int bit[400003] = {0};
	void clear(){
		fill(bit, bit + N + 1, 0);
	}
	void add(int p, int v){
		while(p <= N){
			bit[p] += v;
			p += p & -p;
		}
	}
	int qry(int p){
		int res = 0;
		while(p){
			res += bit[p];
			p -= p & -p;
		}
		return res;
	}
} bit;

void solve(){
	cin >> N;
	int n = N;
	fill(ex, ex + n + 1, 0);
	for(int i = 0; i < n; i++) cin >> A[i], ex[A[i]]++;
	for(int i = 1; i <= n; i++){
		if(ex[i] >= 2){
			cout << "YES\n";
			return;
		}
	}
	int iinv = 0;
	bit.clear();
	for(int i = 0; i < n; i++){
		iinv += bit.qry(A[i]);
		bit.add(A[i], 1);
	}
	cout << ((iinv + ((long long) n * (n - 1) / 2)) % 2 ? "NO\n" : "YES\n");
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--) solve();
}