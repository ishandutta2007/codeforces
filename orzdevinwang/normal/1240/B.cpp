#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 3e5 + 7; 
int n, mx[N], mn[N], a[N], arr[N], atot;
ll k;
bool vis[N];
void Main () {
	atot = 0; 
	cin >> n;
	L(i, 1, n) cin >> a[i], arr[++atot] = a[i];
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) a[i] = lower_bound(arr + 1, arr + atot + 1, a[i]) - arr;
	L(i, 1, atot) mx[i] = -1e9, mn[i] = 1e9;
	L(i, 1, n) {
		mx[a[i]] = max(mx[a[i]], i);
		mn[a[i]] = min(mn[a[i]], i);
	} 
	int cnt = 1, ns = 1;
	L(i, 2, atot) {
		if(mn[i] < mx[i - 1]) 
			cnt = 0;
		cnt += 1;
		ns = max(ns, cnt);
	}
	cout << atot - ns << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main ();
	return 0;
}