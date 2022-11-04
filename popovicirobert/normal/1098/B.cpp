#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

 	cin >> n >> m;
 	vector<string> mat(n);
 	for(i = 0; i < n; i++) {
 		cin >> mat[i];
 	}

 	vector<vector<char>> sol1(n, vector<char>(m));
 	auto sol2 = sol1, aux = sol1;
 	vector<char> ch = {'A', 'G', 'C', 'T'};

 	auto get = [&](int l, int c, char ch) -> int {
 		if(l >= n || c >= m) return 0;
 		return mat[l][c] != ch;
 	};
 	auto set = [&](int l, int c, char ch, auto& sol) {
 		if(l < n && c < m) {
 			sol[l][c] = ch;
 		}
 	};

 	vector<int> p = {0, 1, 2, 3};
 	int mn1 = 1e9;
 	do {
 		int cur = 0;
	 	for(i = 0; i < n; i++) {
	 		int a = 0, b = 0;
	 		int offset = 2 * (i & 1);
	 		for(j = 0; j < m; j += 2) {
	 			a += get(i, j, ch[p[offset]]) + get(i, j + 1, ch[p[offset + 1]]);
	 			b += get(i, j + 1, ch[p[offset]]) + get(i, j, ch[p[offset + 1]]);
	 		}
	 		if(a < b) {
	 			for(j = 0; j < m; j += 2) {
	 				set(i, j, ch[p[offset]], aux);
	 				set(i, j + 1, ch[p[offset + 1]], aux);
	 			}
	 		}
	 		else {
	 			for(j = 0; j < m; j += 2) {
	 				set(i, j, ch[p[offset + 1]], aux);
	 				set(i, j + 1, ch[p[offset]], aux);
	 			}
	 		}
	 		cur += min(a, b);
	  	}
	  	if(mn1 > cur) {
	  		mn1 = cur;
	  		swap(sol1, aux);
	  	}
  	}while(next_permutation(p.begin(), p.end()));

  	p = {0, 1, 2, 3};
 	int mn2 = 1e9;
 	do {
 		int cur = 0;
	 	for(j = 0; j < m; j++) {
	 		int a = 0, b = 0;
	 		int offset = 2 * (j & 1);
	 		for(i = 0; i < n; i += 2) {
	 			a += get(i, j, ch[p[offset]]) + get(i + 1, j, ch[p[offset + 1]]);
	 			b += get(i + 1, j, ch[p[offset]]) + get(i, j, ch[p[offset + 1]]);
	 		}
	 		if(a < b) {
	 			for(i = 0; i < n; i += 2) {
	 				set(i, j, ch[p[offset]], aux);
	 				set(i + 1, j, ch[p[offset + 1]], aux);
	 			}
	 		}
	 		else {
	 			for(i = 0; i < n; i += 2) {
	 				set(i, j, ch[p[offset + 1]], aux);
	 				set(i + 1, j, ch[p[offset]], aux);
	 			}
	 		}
	 		cur += min(a, b);
	  	}
	  	if(mn2 > cur) {
	  		mn2 = cur;
	  		swap(sol2, aux);
	  	}
  	}while(next_permutation(p.begin(), p.end()));

 	auto sol = sol1;
 	if(mn1 > mn2) {
 		swap(sol, sol2);
 	}
 	
 	for(i = 0; i < n; i++) {
 		for(j = 0; j < m; j++) {
 			cout << sol[i][j];
 		}
 		cout << "\n";
 	}

    return 0;
}