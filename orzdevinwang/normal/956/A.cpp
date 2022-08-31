#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 107;
int n, m;
char s[N][N];
bool vis1[N], vis2[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) {
		cin >> (s[i] + 1);	
	}
	L(i, 1, n) {
		L(j, 1, m) if(s[i][j] == '#') {
			vi A, B;
			L(t, i, n) {
				if(s[t][j] == '#') A.push_back(t);
			}
			L(t, j, m) {
				if(s[i][t] == '#') B.push_back(t);
			}
			for(const int &w : A) if(vis1[w]) return cout << "No\n", 0;
			for(const int &c : B) if(vis2[c]) return cout << "No\n", 0;
			for(const int &w : A) {
				vis1[w] = true;
				for(const int &c : B) {
					vis2[c] = true;
					if(s[w][c] == '.') return cout << "No\n", 0;
					s[w][c] = '.';
				}
			}
		}
	}
	cout << "Yes\n";
	return 0;
}