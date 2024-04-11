#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7, inv6 = (mod + 1) / 6, W = 2;
int n, a[N], ns[N];
void work (int x, int y, int z) {
	int sum = (a[x] + a[y] + a[z]) / 2, tp = 3;
	ns[1] = sum - a[x], ns[2] = sum - a[y], ns[3] = sum - a[z];
	L(i, 1, n) if(i != x && i != y && i != z) 
		ns[++tp] = a[i] - ns[1];
	cout << "YES\n";
	L(i, 1, n) cout << ns[i] << ' ';
	cout << '\n';
}
int z;
short h[N * 10][11], s[N];
int arr[N];
bool vis[N * 11], vs[N];
void dfs (int x, int k, int sum) {
	if(k == z + 1) {
		if(vis[sum])  {
			int tot = 0;
			L(i, 0, z - 1) vs[h[sum][i]] ^= 1;
			L(i, 0, z - 1) vs[s[i]] ^= 1;
			vi S1, S2; 
			L(i, 0, z - 1) 
				if(vs[h[sum][i]]) 
					S1.push_back(h[sum][i]);
			L(i, 0, z - 1) 
				if(vs[s[i]]) 
					S2.push_back(s[i]);
			assert (sz(S1) == sz(S2));
			L(i, 0, sz(S1) - 1) arr[++tot] = S1[i], arr[++tot] = S2[i];
			cout << "YES\n";
			ns[1] = 0;
			L(i, 2, tot) ns[i] = a[arr[i - 1]] - ns[i - 1];
			L(i, 1, n) if(!vs[i]) ++tot, ns[tot] = a[i];
			assert (tot == n);
			L(i, 1, n) cout << ns[i] << ' ';
			exit(0);
			return ;
		}
		L(i, 0, z - 1) h[sum][i] = s[i];
		vis[sum] = 1;
		return ;
	}
	L(i, x + 1, n) 
		s[k - 1] = i, dfs (i, k + 1, sum + a[i]);	
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	L(i, 1, n - 1) {
		if(a[i] == a[i + 1]) {
			ns[1] = 0, ns[2] = a[i];
			int tp = 2;
			L(j, 1, n) 
				if(j != i && j != i + 1) 
					ns[++tp] = a[j];
			cout << "YES\n";
			L(j, 1, n) cout << ns[j] << ' ';
			cout << '\n';
			return 0;
		}
	}
	
	sort(a + 1, a + n + 1, [&] (int x, int y) {
		return (x & 1) < (y & 1);
	});
	
	L(i, 1, n) 
		L(j, i + 1, n) 
			L(k, j + 1, n) 
				if(!((a[i] + a[j] + a[k]) & 1)) 
					return work (i, j, k), 0;
	
	z = min(9, n / 2);
	dfs (0, 1, 0);
	cout << "NO\n";
	return 0;
}