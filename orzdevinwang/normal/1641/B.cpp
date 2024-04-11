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
vector < pair < int, int > > vc;
vi tns;

int n, a[N];
void Main() {
	vc.clear();
	tns.clear();
	cin >> n;
	L(i, 1, n) cin >> a[i];
	int cur = 0;
	for(int i = 1; i <= n; i += 2) {
		int mat = 0;
		L(j, i + 1, n) if(a[i] == a[j]) {
			mat = j;
			break ;
		}
		if(!mat) return cout << -1 << '\n', void ();
		L(j, i + 1, mat - 1) 
			vc.push_back(make_pair(mat + cur + (j - i - 1), a[j]));
		cur += (mat - i - 1) * 2;
		reverse(a + i + 1, a + mat + 1);
		tns.push_back((mat - i) * 2);
	} 
	cout << sz(vc) << '\n';
	for(auto u : vc) 
		cout << u.first << ' ' << u.second << '\n';
	cout << sz(tns) << '\n';
	for(const int &u : tns) 
		cout << u << ' ';
	cout << '\n' ;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}