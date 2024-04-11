#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e5 + 7;
int n, m;
vector < int > vx[N], vy[N];
ll ns = 0;
void count(vi x) {
	if(!sz(x)) return ;
	sort(x.begin(), x.end());
	L(i, 1, sz(x) - 1) {
		ns += (ll) (x[i] - x[i - 1]) * i * (sz(x) - i);
	}
} 
void Main () {
	cin >> n >> m;
	L(i, 1, n) 
		L(j, 1, m) {
			int w;
			cin >> w;
			vx[w].emplace_back(i);
			vy[w].emplace_back(j);
		}
	L(i, 1, N - 1) count(vx[i]), count(vy[i]);
	cout << ns << '\n';
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Main();
	return 0;
}