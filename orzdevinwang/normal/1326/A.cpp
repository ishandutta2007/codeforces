#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 4005, mod = 1e9 + 7;
int n;
void Main () {
	cin >> n;
	if(n == 1) 
		cout << "-1\n";
	else {
		L(i, 1, n - 1) cout << 5;
		cout << "4\n";
	}
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}