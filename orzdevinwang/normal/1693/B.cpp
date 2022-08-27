#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7;
int n, p[N];
ll l[N], r[N], v[N];
/*
*/
void Main() {
	cin >> n;
	L(i, 0, n) v[i] = 0;
	L(i, 2, n) cin >> p[i];
	L(i, 1, n) cin >> l[i] >> r[i];
	int cnt = 0;
	R(i, n, 1) {
		v[i] = min(v[i], r[i]);
		if(v[i] < l[i]) cnt += 1, v[i] = r[i];
		v[p[i]] += v[i];
	} 
	cout << cnt << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}