#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 1e6 + 7;
int n, m, ord[N], w[N];
bool mp[N];
ll ns, lst;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) {
		cout << "? ";
		L(j, 1, m) cout << (i == j);
		cout << endl;
		cin >> w[i], ord[i] = i;
	}
	sort(ord + 1, ord + m + 1, [&] (int x, int y) {
		return w[x] < w[y];
	});
	L(t, 1, m) {
		int x = ord[t];
		mp[x] = 1;
		 
		ll c;
		cout << "? ";
		L(i, 1, m) cout << mp[i];
		cout << endl;
		cin >> c;
		
		if(lst + w[x] == c) ns += w[x];
		lst = c;
	}
	cout << "! " << ns << endl;
	return 0;
}