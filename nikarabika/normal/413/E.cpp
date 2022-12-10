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

const int maxn = 200 * 1000,
	  Inf = 1000 * 1000 * 100;

struct node{
	int a[2][2];
	node(){
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				a[i][j] = Inf;
	}
	int* operator[](int i){
		return a[i];
	}
}seg[maxn * 4];

int n, q;
char a[2][maxn];

node merge(node le, node ri){
	node ret;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++)
				smin(ret[i][j], le[i][k] + ri[k][j] + 1);
	return ret;
}

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id][0][0] = (a[0][l] == 'X') * Inf;
		seg[id][1][1] = (a[1][l] == 'X') * Inf;
		if(a[0][l] == '.' and a[1][l] == '.') seg[id][0][1] = seg[id][1][0] = 1;
		else seg[id][0][1] = seg[id][1][0] = Inf;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

node get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	if(en <= mid)
		return get(st, en, l, mid, id * 2 + 0);
	if(st >= mid)
		return get(st, en, mid, r, id * 2 + 1);
	return merge(get(st, en, l, mid, id * 2 + 0),
		   get(st, en, mid, r, id * 2 + 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	build();
	for(int i = 0; i < q; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		if(fi % n > se % n)
			swap(fi, se);
		int val = get(fi % n, (se % n) + 1)[fi / n][se / n];
		cout << (val < 4 * maxn ? val : -1) << '\n';
	}
	return 0;
}