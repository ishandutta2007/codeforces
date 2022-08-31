#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 47;
int n, k, col[N], cl[N][N], ns = true;
vi J[N];
void dfs (int x, int all) {
	if(x == k + 1) {
		L(i, 1, all) if(col[i] != 0) ns = false;
		L(i, all + 1, n) if(col[i] != 1) ns = false;
		return ;
	}
	
	L(i, 1, n) cl[x][i] = col[i];
	int ntz = 0, nt0 = 0;
	L(i, 0, sz(J[x]) - 1) ntz += col[J[x][i]] == -1, nt0 += col[J[x][i]] == 0;
	L(r, 0, ntz) {
		L(i, 0, sz(J[x]) - 1) col[J[x][i]] = i >= r + nt0;
		dfs (x + 1, all + r) ;
	}
	L(i, 1, n) col[i] = cl[x][i];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> k;
	if(n == 1) 
		return cout << "ACCEPTED\n", 0;
	
	L(i, 1, k) {
		int s, w; 
		cin >> s;
		while (s--) cin >> w, J[i].push_back(w);
	}
	L(i, 1, n) col[i] = -1;
	dfs (1, 0);
	if (ns) cout << "ACCEPTED\n";
	else cout << "REJECTED\n";
	return 0;
}