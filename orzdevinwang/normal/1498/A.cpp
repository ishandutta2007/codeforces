#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
ll n;
ll cnt(ll x) {
	return x >= 10 ? cnt(x / 10) + x % 10 : x % 10;
}
void Main() {
	cin >> n;
	while(__gcd(n, cnt(n)) == 1) ++n;
	cout << n << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}