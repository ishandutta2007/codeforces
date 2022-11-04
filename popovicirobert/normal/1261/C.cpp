#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int


    
using namespace std;

  
int main() {
#ifdef HOME
    ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
	int i, j, n, m;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	
	vector < vector <int> > sp(n + 1, vector <int>(m + 1));
	vector <string> str(n + 1);
	
	for(i = 1; i <= n; i++) {
		cin >> str[i];
		str[i] = " " + str[i];
		for(j = 1; j <= m; j++) {
			sp[i][j] = sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1] + (str[i][j] == 'X');
		}
	}
	
	vector < vector <int> > aux(n + 2, vector <int>(m + 2));
	
	auto check = [&](int n, int m, int res) -> bool {
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				aux[i][j] = 0;
			}
		}
		
		int len = 2 * res + 1;
		for(i = 1; i + len - 1 <= n; i++) {
			for(j = 1; j + len - 1 <= m; j++) {
				if(sp[i + len - 1][j + len - 1] - sp[i - 1][j + len - 1] - sp[i + len - 1][j - 1] + sp[i - 1][j - 1] == len * len) {
					aux[i][j]++;
					aux[i + len][j]--;
					aux[i][j + len]--;
					aux[i + len][j + len]++;
				}
			}
		}
		
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				aux[i][j] += aux[i - 1][j] + aux[i][j - 1] - aux[i - 1][j - 1];
				if(aux[i][j] == 0 && str[i][j] == 'X') {
					return 0;
				}
			}
		}
		
		return 1;
	};
	
	int res = 0;
	for(int step = 1 << 17; step; step >>= 1) {
		if(check(n, m, res + step)) {
			res += step;
		}
	}
	
	cout << res << "\n";
	
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			str[i][j] = '.';
		}
	}
	
	int len = 2 * res + 1;
	for(i = 1; i + len - 1 <= n; i++) {
		for(j = 1; j + len - 1 <= m; j++) {
			if(sp[i + len - 1][j + len - 1] - sp[i - 1][j + len - 1] - sp[i + len - 1][j - 1] + sp[i - 1][j - 1] == len * len) {
				str[i + len / 2][j + len / 2] = 'X';
			}
		}
	}
	
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			cout << str[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}