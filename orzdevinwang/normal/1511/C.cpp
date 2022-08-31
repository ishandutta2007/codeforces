#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 5e5 + 7;
int n, m, a[N], pos[N], all = 50;
int vis[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> a[i];
	R(i, n, 1) vis[a[i]] = i;
	while(m--) {
		int p;
		cin >> p;
		cout << vis[p] << " ";
		L(i, 1, 50) if(vis[i] < vis[p]) vis[i] ++;
		vis[p] = 1;
	}
	return 0;
} 
// To Cheat, To attack!