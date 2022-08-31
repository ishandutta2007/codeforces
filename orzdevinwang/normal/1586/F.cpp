#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2007; 
int n, m;
int e[N][N];
int calc (vector < vi > S, int d) {
	int n = sz(S);
	vector < vi > H;
	for (int l = 0; l < n; l += m) {
		int r = min(l + m - 1, n - 1);
		L(i, l, r) 
			L(j, i + 1, r) 
				for (const int &u : S[i]) 
					for (const int &v : S[j]) 
						e[u][v] = d;
		vi R;
		L(i, l, r) 
			for (const int &x : S[i])
				R.push_back(x);
		H.push_back(R) ;
	}
	if(sz(H) == 1) return d;
	return calc (H, d + 1);
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	vector < vi > S;
	L(i, 1, n) S.push_back(vi {i});
	cout << calc (S, 1) << '\n';
	L(i, 1, n) 
		L(j, i + 1, n) 
			cout << e[i][j] << ' ';
	cout << '\n';
	return 0;
}