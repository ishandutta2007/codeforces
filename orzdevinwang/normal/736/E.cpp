#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 3333, mod = 1e9 + 7;
int n, m, d[N];
char ns[N][N];
struct node {
	int id, v;
} a[N];
void draw(int x, int y) { ns[x][y] = ns[y][x] = 'D'; }
void win(int x, int y) { ns[x][y] = 'W', ns[y][x] = 'L'; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	L(i, 1, n) a[i].id = i, ns[i][i] = 'X';
	L(i, 1, m) cin >> a[i].v;
	int sum = 0;
	L(i, 1, m) {
		sum += 2 * (n - i), sum -= a[i].v;
		if(sum < 0) return cout << "no\n", 0;	
	}
	sum = n * (n - 1);
	L(i, 1, m) sum -= a[i].v;
	if(n > m) {
		int d = sum / (n - m), r = sum % (n - m);
		if((!!r) + d > a[m].v) return cout << "no\n", 0;
		L(i, m + 1, n) {
			a[i].v = d;
			if(r) ++ a[i].v, --r;
		}
	}
//	L(i, 1, n) cout << a[i].v << " ";
//	cout << "\n";
	L(i, 1, n) {
		sort(a + i, a + n + 1, [&] (node aa, node bb) { return aa.v == aa.v ? aa.id < bb.id : aa.v > bb.v; });
		priority_queue < pair<int, int> > q;
		L(z, i + 1, n) a[z].v -= 2, q.push(make_pair(-a[z].v, z)), win(a[z].id, a[i].id);
		memset(d, 0, sizeof(d));
		while(a[i].v) {
			int u = q.top().second;
			q.pop();
			++a[u].v, --a[i].v; 
			if(!d[u]) d[u] = true, draw(a[u].id, a[i].id), q.push(make_pair(-a[u].v, u));
			else win(a[i].id, a[u].id);
		}
	}
	cout << "yes\n";
	L(i, 1, n) cout << (ns[i] + 1) << "\n";
	return 0;
}