#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
#define i128 __int128
using namespace std;
const int N = 1e6 + 7;
int T, n, x, a[N], b[N];
bool check(int x) {
	int t = sqrt(x);
	return t * t == x;
}
void Main() {
	cin >> n;
	if(n % 2 == 0 && (check(n) || check(n / 2))) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) Main();
	return 0;
}