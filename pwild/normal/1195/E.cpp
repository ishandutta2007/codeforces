#include <bits/stdc++.h>
using namespace std;

#define FORN(i,n) for (int i = 0; i < (n); i++)

const int N = 3010;
int a[N][N];

int main() {
	int m, n, mm, nn;
	cin >> m >> n >> mm >> nn;

	int g, x, y, z;
	cin >> g >> x >> y >> z;
	
	FORN(i,m) FORN(j,n) {
		a[i][j] = g;
		g = (g * 1LL * x + y) % z;
	}
	
	FORN(dir,2) {
		FORN(i,m) {
			deque<pair<int,int>> Q; // (index,value)
			FORN(j,n) {
				if (j >= nn) a[i][j-nn] = Q.front().second;
				
				while (!Q.empty() && Q.back().second >= a[i][j]) Q.pop_back();
				Q.emplace_back(j,a[i][j]);

				if (Q.front().first == j-nn) Q.pop_front();
			}
			a[i][n-nn] = Q.front().second;
		}

		n -= nn-1;
		
		FORN(i,N) FORN(j,i) swap(a[i][j],a[j][i]);
		swap(m,n), swap(mm,nn);
	}
	
	long long res = 0;
	FORN(i,m) FORN(j,n) res += a[i][j];
	cout << res << endl;
}