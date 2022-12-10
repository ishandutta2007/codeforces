//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Iz wayTn' 230u :)

typedef pair<int, int> pii;

#define BP __builtin_popcount
#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69, maxl = 20;
int sparse_min[maxn][maxl], sparse_prepro[maxn];
int a[maxn];
int n;
vector<pii> ans;

int min_merge(int id1, int id2){
	return a[id1] < a[id2] ? id1 : id2;
}

void build_sparse_table(void){
	for(int i = 0; i < n; i++)
		sparse_min[i][0] = i;
	for(int j = 1; j < maxl; j++){
		for(int i = 0; i + (1 << j) < maxn; i++)
			sparse_min[i][j] = min_merge(sparse_min[i][j - 1], sparse_min[i + (1 << (j - 1))][j - 1]);
	}
	for(int i = 1; i < maxn; i++){
		if(BP(i) == 1){
			for(int j = 0; j < maxl; j++)
				if((i >> j) & 1)
					sparse_prepro[i] = j;
		}
		else
			sparse_prepro[i] = sparse_prepro[i - (i & -i)];
	}
	return;
}

void solve(int st, int en, int flr = 0){
	if(st >= en)
		return;
	int loglen = sparse_prepro[en - st];
	int id_min = min_merge(sparse_min[st][loglen],
			sparse_min[en - (1 << loglen)][loglen]);
	for(int i = flr; i < a[id_min]; i++)
		ans.PB(MP(st + 1, en));
	solve(st, id_min, a[id_min]);
	solve(id_min + 1, en, a[id_min]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	build_sparse_table();
	solve(0, n);
	cout << ans.size() << '\n';
	for(auto x : ans)
		cout << x.L << ' ' << x.R << '\n';
	return 0;
}