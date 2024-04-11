#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
int T, n, a[N], stk[N], tp;
void Main() {
	tp = 0;
	cin >> n;
	L(i, 1, n) cin >> a[i];
	
	L(i, 0, n + 1) stk[i] = 0;
	
	L(i, 1, n) {
		++tp, stk[tp] = 0;
		while(tp > 0 && stk[tp] + 1 != a[i]) --tp;
		stk[tp]++;
		L(a, 1, tp - 1) cout << stk[a] << ".";
		cout << stk[tp] << "\n";
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) Main();
	return 0;
}