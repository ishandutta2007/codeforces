#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, m, a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> n;
	L(i, 1, n) cout << (i % 2);
	return 0;
}