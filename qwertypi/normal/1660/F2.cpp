#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int s[200002];

int n;

struct BIT{
	int bit[400023] = {0};
	void clear(){
		fill(bit, bit + n * 2 + 20, 0);
	}
	void add(int p, int v){
		while(p <= n * 2 + 19){
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
	cin >> n;
	string S;
	cin >> S;
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + (S[i] == '+' ? 1 : -1);
	}
	int ans = 0;
	for(int r = 0; r < 3; r++){
		bit.clear();
		for(int i = 0; i <= n; i++){
			if(s[i] % 3 == r || s[i] % 3 == r - 3){
				ans += bit.qry(n + 3 - s[i] + 1);
				bit.add(n + 3 - s[i], 1);
			}
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}