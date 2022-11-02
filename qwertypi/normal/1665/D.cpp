// 
// 

#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)

using namespace std;

const int mod = 1e9 + 7;

int A[300001];
int f(int x){
	return (1 << 30) - x;
}
void solve(){
	int m = 0;
	for(int j = 0; j <= 29; j++){
		cout << "? " << f(m + (1 << j)) << ' ' << f(m + (1 << j)) + (1 << j + 1) << endl;
		int v; cin >> v;
		if(v >= (1 << j + 1)) m |= (1 << j);
	}
	cout << "! " << m << endl;
}

int32_t main(){
	int t; cin >> t;
	while(t--) solve();
}