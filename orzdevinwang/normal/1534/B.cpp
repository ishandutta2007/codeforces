#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N];
void Main() {
	cin >> n;
	ll ns = 0;
	a[n + 1] = 0;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) if(a[i] > a[i - 1] && a[i] > a[i + 1]) 
		ns += a[i] - max(a[i - 1], a[i + 1]), a[i] = max(a[i - 1], a[i + 1]);
	L(i, 1, n + 1) ns += abs(a[i] - a[i - 1]);
	cout << ns << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}