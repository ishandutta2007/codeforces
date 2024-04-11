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

const int maxn = 1000;
bool mark[maxn][maxn];
int a[maxn][maxn];
vector<int> vec[maxn];
int n, m;

bool check(int mn){
	for(int i = 0; i < n; i++){
		vec[i].clear();
		for(int j = 0; j < m; j++)
			if(a[i][j] >= mn)
				vec[i].PB(j);
	}
	memset(mark, false, sizeof mark);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < sz(vec[i]); j++)
			for(int k = 0; k < j; k++)
				if(mark[vec[i][j]][vec[i][k]]) return true;
				else mark[vec[i][j]][vec[i][k]] = true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		vec[i].reserve(1 << 10);
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	int lo = 0, hi = 1000000000 + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(check(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
	return 0;
}