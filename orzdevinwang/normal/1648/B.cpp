#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7;
int n, c, a[N];
bool vis[N];
int pre[N];
void Main () {
	cin >> n >> c;
	L(i, 1, n) {
		cin >> a[i];
		vis[a[i]] = true;
	}
	L(i, 1, c) {
		pre[i] = pre[i - 1] + vis[i];
	}
	bool ok = true;
	L(i, 1, c) if(!vis[i]) {
		L(y, 1, c / i) if(vis[y]) {
			int l = y * i, r = min(c, y * (i + 1) - 1);
			if(pre[r] - pre[l - 1]) ok = false;
		}
	}
	if(ok) cout << "Yes\n";
	else cout << "No\n";
	L(i, 1, c) vis[i] = false, pre[i] = 0;
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}