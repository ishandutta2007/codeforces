#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
int n;
ll a[N]; 
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ns = 0;
	L(i, 1, n) ns += a[i] * (n + 1 - i * 2);
	cout << ns + a[n] << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}