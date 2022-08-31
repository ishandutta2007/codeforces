#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 7;
ll n, m, d;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> d;
	cout << d * 2 + min(n, m) * 2 + (n != m) << "\n";
	return 0;
}