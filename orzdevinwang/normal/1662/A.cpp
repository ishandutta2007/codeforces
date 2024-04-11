#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
int w[11];
void Main() {
	me(w, 0);
	int n;
	cin >> n;
	L(i, 1, n) {
		int x, y;
		cin >> x >> y, swap(x, y);
		w[x] = max(w[x], y);
	}
	L(i, 1, 10) 
		if(!w[i])
			return cout << "MOREPROBLEMS\n", void();
	int ns =0 ;
	L(i, 1, 10) ns += w[i];
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0; 
}