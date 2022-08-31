#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, fa[N], cnt[N], deg[N], rd[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 2, n) cin >> fa[i], deg[fa[i]] += 1;
	L(i, 2, n) if(!deg[i]) {
		rd[fa[i]] += 1;
	} 
	L(i, 1, n) if(deg[i] && rd[i] < 3) return cout << "No\n", 0;
	cout << "Yes\n";
	return 0;
}