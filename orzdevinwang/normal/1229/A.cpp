#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, m, b[N];
ll a[N];
bool vis[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cin >> b[i];
	ll ns = 0;
	L(i, 1, n) {
		bool op = false;
		L(j, i + 1, n) if(a[j] == a[i]) op = true;
		if(!op) continue ; 
		L(j, 1, n) if((a[j] & a[i]) == a[j]) vis[j] = true;
	}
	L(i, 1, n) if(vis[i]) ns += b[i];
	cout << ns << '\n';
	return 0;
}