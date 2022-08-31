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
const int N = 2e5 + 7, All = 1e9 + 7, M = N * 20;
int n, m, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	while(k--) {
		int x, y;
		cin >> x >> y;
		if(x <= 5 || y <= 5 || x + 5 >= n + 1 || y + 5 >= m + 1) 
			return cout << "YES\n", 0;
	}
	cout << "NO\n";
	return 0;
}