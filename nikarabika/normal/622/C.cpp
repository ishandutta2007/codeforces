//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2e5 + 85 - 69, maxl = 20;
int a[maxn], dpsp[maxn], Min[maxn][maxl], Max[maxn][maxl];
int n, q;

int MiN(int id1, int id2){
	if(a[id1] < a[id2])
		return id1;
	return id2;
}

int MaX(int id1, int id2){
	if(a[id1] > a[id2])
		return id1;
	return id2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		Max[i][0] = Min[i][0] = i;
	}
	for(int i = 2; i < maxn; i++)
		dpsp[i] = dpsp[i >> 1] + 1;
	for(int j = 1; j < maxl; j++)
		for(int i = 0; i + (1 << j) <= n; i++){
			Min[i][j] = MiN(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
			Max[i][j] = MaX(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
		}
	while(q--){
		int l, r, x;
		cin >> l >> r >> x;
		l--;
		int len = r - l;
		int MIN = MiN(Min[l][dpsp[len]], Min[r - (1 << dpsp[len])][dpsp[len]]),
			MAX = MaX(Max[l][dpsp[len]], Max[r - (1 << dpsp[len])][dpsp[len]]);
		if(a[MIN] != x)
			cout << MIN + 1 << '\n';
		else if(a[MAX] != x)
			cout << MAX + 1 << '\n';
		else
			cout << "-1\n";
	}
	return 0;
}