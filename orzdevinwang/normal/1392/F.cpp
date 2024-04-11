#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
ll n, a, sum;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	cin >> n;
	L(i, 0, n - 1) cin >> a, sum += a - i;
	L(i, 0, n - 1) cout << sum / n + (sum % n > i) + i << ' '; 
	return 0;
}