#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1e5 + 7;
int n, dp[N];
char s[N], z[N];
void Main () {
	cin >> n >> (s + 1);
	L(i, 1, n) z[i] = s[i];
	sort(z + 1, z + n + 1);
	int ns = 0;
	L(i, 1, n) if(z[i] != s[i]) ns ++;
	cout << ns << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}