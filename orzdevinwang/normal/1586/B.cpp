#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1e6 + 7; 
int n, m, vis[N];
void Main () {
	cin >> n >> m;
	L(i, 1, n) vis[i] = 0;
	L(i, 1, m) {
		int a, b, c;
		cin >> a >> b >> c;
		vis[b] = 1;
	}
	L(i, 1, n) {
		if(!vis[i]) {
			L(j, 1, n) if(j != i) cout << i << ' ' << j << '\n';
			return ;
		}
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