#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 4e5 + 7;
int n, a[N], fr[N], to[N], tp, sr[N];
int f[N], deg[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
} 
void Main () {
	cin >> n;
	L(i, 1, n) deg[i] = 0, f[i] = i;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) {
		if(!deg[a[i]]) deg[a[i]] = 1, sr[a[i]] = i, f[i] = find(a[i]);
	}
	tp = 0;
	L(i, 1, n) if(!deg[i]) ++ tp, fr[tp] = i, to[tp] = find(i);
	if(tp == 1 && fr[tp] == to[tp]) {
		int u = fr[tp];
		cout << n - 1 << "\n";
		a[sr[a[u]]] = u;
		L(i, 1, n) cout << a[i] << ' ';
		cout << "\n";
		return ;
	} 
	
	cout << n - tp << "\n";
	L (i, 1, tp) a[to[i]] = fr[i % tp + 1];
	L(i, 1, n) cout << a[i] << " ";
	cout << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main(); 
	return 0;
}