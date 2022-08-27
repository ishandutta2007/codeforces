#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
using namespace std;
const int N = 1e3 + 7, mod = 998244353;
int n, s;
void Main () {
	cin >> n >> s;
	int Mid = (n + 1) / 2;
	cout << s / (n - Mid + 1) << '\n';
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}