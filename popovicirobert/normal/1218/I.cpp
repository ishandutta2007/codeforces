#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x)) 
    
using namespace std;
    
const int MAXN = 2000;
   
bitset <MAXN> c;
   
int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
		
 	cin >> n;

	vector < bitset <MAXN> > a(n), b(n);
	for(i = 0; i < n; i++) {
		string str;
		cin >> str;
		for(j = 0; j < n; j++) {
			a[i][j] = str[j] - '0';
		}
	}
	for(i = 0; i < n; i++) {
		string str;
		cin >> str;
		for(j = 0; j < n; j++) {
			b[i][j] = str[j] - '0';
		}
	}

	string str;
	cin >> str;
	for(i = 0; i < n; i++) {
		c[i] = str[i] - '0';
	}

	vector < vector < pair <int, bool> > > g(2 * n + 2);

	auto addEdge = [&](int x, int y, bool t) -> void {
		g[x].push_back({y, t});
		g[y].push_back({x, t});
	};

	addEdge(2 * n, 2 * n + 1, 1);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(a[i][j] == b[i][j]) {
				if(c[i] == 0 && c[j] == 1) {
					addEdge(2 * n, i,  0);
				}
				if(c[i] == 1 && c[j] == 0) {
					addEdge(2 * n, j + n, 0);
				}
				if(c[i] == 1 && c[j] == 1) {
					addEdge(i, j + n, 0);
				}
			}
			else {
				if(c[i] == 0 && c[j] == 0) {
					cout << -1;
					return 0;
				}
				if(c[i] == 0 && c[j] == 1) {
					addEdge(2 * n + 1, i, 0);
				}
				if(c[i] == 1 && c[j] == 0) {
					addEdge(2 * n + 1, j + n, 0);
				}
				if(c[i] == 1 && c[j] == 1) {
					addEdge(i, j + n, 1);
				}
			}
		}
	}

	vector <int> col(2 * n + 2, -1);

	function <void(int, int)> dfs = [&](int nod, int c) {
		col[nod] = c;
		for(auto it : g[nod]) {
			if(col[it.first] == -1) {
				dfs(it.first, it.second ^ c);
			}
		}
	};

	dfs(2 * n, 0);
	for(i = 0; i < 2 * n + 2; i++) {
		if(col[i] == -1) 
			dfs(i, 0);
	}

	/*for(i = 0; i < 2 * n + 2; i++) {
		cerr << i << ": ";
		for(auto it : g[i]) {
			cerr << it.first << " " << it.second << "  ";
		}
		cerr << "\n";
	}*/

	for(i = 0; i < 2 * n + 2; i++) {
		if(col[i] == -1) continue;
		for(auto it : g[i]) {
			if((col[i] ^ col[it.first]) != it.second) {
				cout << -1;
				return 0;
			}
		}
	}

	/*for(i = 0; i < 2 * n; i++) {
		cerr << col[i] << " ";
	}
	cerr << "\n";*/

	vector < pair <int, bool> > sol;
	for(i = 0; i < n; i++) {
		if(col[i] == 1) sol.push_back({i, 0});
		if(col[i + n] == 1) sol.push_back({i, 1});
	}

	cout << sol.size() << "\n";
	for(auto it : sol) {
		if(it.second == 0) {
			cout << "row " << it.first << "\n";
		}
		else {
			cout << "col " << it.first << "\n";	
		}
	}
            
	return 0;
}