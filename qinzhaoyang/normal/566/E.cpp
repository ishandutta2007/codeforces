#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int n , e[N][N] , u[N] , v[N] , cnt = 0 , is[N];
bitset <N> a[N] , b[N];

int main() {
	cin >> n; int flag = true;
	for(int i = 1 , k, v; i <= n; i++) {
		cin >> k; if(k != n) flag = false; 
		for(int j = 1; j <= k; j++) cin >> v , a[i][v] = 1; 
	}
	if(flag) {
		for(int i = 1; i < n; i++)
			cout << i << " " << n << endl;
		return 0;
	}
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++) {
			bitset <N> t = a[i] & a[j];
			if(t.count() == 2) {
				int x = t._Find_first() , y = t._Find_next(x);
				if(e[x][y]) continue;
				u[++cnt] = x , v[cnt]  = y , is[x] = is[y] = 1;
				e[x][y] = e[y][x] = 1;
			}
		}
	if(cnt == 1) {
		int t1 = u[1] , t2 = v[1] , t = 0;
		for(int i = 1; i <= n; i++) if(a[i].count() != n) {
			t = i; break;
		}
		cout << t1 << " " << t2 << endl;
		for(int i = 1; i <= n; i++) if(a[t][i] && i != t1 && i != t2)
			cout << t1 << " " << i << endl;
		for(int i = 1; i <= n; i++) if(!a[t][i] && i != t1 && i != t2)
			cout << t2 << " " << i << endl;
		return 0; 
	}
	for(int i = 1; i <= n; i++)
		if(is[i]) b[i][i] = 1;
	for(int i = 1; i <= cnt; i++)
		b[u[i]][v[i]] = 1 , b[v[i]][u[i]] = 1;
	for(int i = 1; i <= n; i++) if(!is[i]) {
		int Min = n + 1 , s = 0;
		for(int j = 1; j <= n; j++) if(a[j][i] && a[j].count() < Min)
			Min = a[j].count() , s = j;
		bitset <N> c = a[s];
		for(int j = 1; j <= n; j++) if(c[j] == 1 && !is[j])
			c[j] = 0;
		int A = 0;
		for(int j = 1; j <= n; j++) if(is[j] && c == b[j])
			A = j;
		u[++cnt] = i , v[cnt] = A;
	}
	for(int i = 1; i <= cnt; i++) cout << u[i] << " " << v[i] << endl;
	return 0;
}