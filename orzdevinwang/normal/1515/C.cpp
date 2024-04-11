#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
#define i128 __int128
using namespace std;
const int N = 1e6 + 7;
int T, n, m, x, a[N], sum[N];
priority_queue < pair < int, int > > q;
void Main() {
	cin >> n >> m >> x;
	L(i, 1, n) cin >> a[i];
	L(i, 1, m) sum[i] = 0, q.push(make_pair(-sum[i], i));
	cout << "YES\n";
	L(i, 1, n) {
		int u = q.top().second;
		q.pop();
		cout << u << " ", sum[u] += a[i], q.push(make_pair(-sum[u], u));
	}
	cout << "\n";
	
	while(!q.empty()) q.pop();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) Main();
	return 0;
}