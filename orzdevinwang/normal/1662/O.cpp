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

int n;
int f[N];

inline int P(int x, int y) {
	y %= 360, (y += 360) %= 360;
	return x * 360 + y;
}

inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool vis1[25][365];
bool vis2[25][365];
char s[100];

void Main() {
	cin >> n;
	me(vis1, true);
	me(vis2, true);
	L(i, 0, 360 * 23) 
		f[i] = i;
	L(t, 1, n) {
		int r, tl, tr;
		cin >> (s + 1);
		if(s[1] == 'C') {
			cin >> r >> tl >> tr;
			for(int i = tl; i != tr; i = (i + 1) % 360) 
				vis1[r][i] = false;
		} else {
			cin >> tl >> tr >> r;
			for(int i = tl + 1; i <= tr; ++i) 
				vis2[i][r] = false;
		}
	}
	L(i, 0, 21) {
		L(j, 0, 359) {
			if(vis1[i][j]) {
				f[find(P(i, j))] = find(P(i + 1, j));
			} 
			
			if(vis2[i][j]) {
				f[find(P(i, j))] = find(P(i, j - 1));
			}
		}
	}
	if(find(P(0, 0)) == find(P(21, 0))) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0; 
}