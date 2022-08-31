#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20, M = 1 << 6;
int n, v[N], d[N];
ll p[N];
bool vis[N];
void workv (int x) {
	int w = v[x];
	while (x < n && w > 0) {
		++ x;
		if(vis[x]) p[x] -= w, w -= 1;
	}
}
void workd (int x) {
	L(i, x + 1, n) p[i] -= d[x];
}
vi S;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n ;
	L(i, 1, n) cin >> v[i] >> d[i] >> p[i], vis[i] = true;
	L(i, 1, n) if(vis[i]) {
		workv (i);
		S.push_back(i);
		L(j, i + 1, n) if(vis[j] && p[j] < 0) vis[j] = false, workd (j);
	}
	cout << sz(S) << '\n';
	for (const int &t : S) cout << t << ' ';
	cout << '\n';
	return 0;
}