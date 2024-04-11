#include <bits/stdc++.h>

using namespace std;

const int N = 100010;	
const int K = 22;

int n, k;
int a[N];
int cnt[N];
int currL = 1;
int currR = 1;
long long f[N][K];
long long currCost;

void del(int x){
	x = a[x];
	--cnt[x];
	currCost -= cnt[x];
}

void ins(int x){
	x = a[x];
	currCost += cnt[x];
	++cnt[x];
}

void upd(int l, int r){
	while(currL > l) ins(--currL);
	while(currL < l) del(currL++);
	while(currR > r) del(currR--);
	while(currR < r) ins(++currR);
}

queue < pair < pair < int, int >, pair < int, int > > > bfs;

void calc(int l, int r, int x, int y, int d){
	if(l > r) return;
	int mid = l + r >> 1;


	f[mid][d] = 1e18;

	int best = -1;

	for(int i = x; i <= min(mid, y); ++i){
		upd(i, mid);
		if(currCost + f[i - 1][d - 1] < f[mid][d]){
			f[mid][d] = currCost + f[i - 1][d - 1];
			best = i;
		}
	}
	bfs.push(make_pair(make_pair(l, mid - 1), make_pair(x, best)));
	bfs.push(make_pair(make_pair(mid + 1, r), make_pair(best, y)));
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	cnt[a[1]] = 1;

	memset(f, 60, sizeof f);
	f[0][0] = 0;


	for(int j = 1; j <= k; ++j){
		bfs.push(make_pair(make_pair(1, n), make_pair(1, n)));
		while(!bfs.empty()){
			auto p = bfs.front();
			bfs.pop();
			calc(p.first.first, p.first.second, p.second.first, p.second.second, j);
		}
	}

	cout << f[n][k];

	return 0;
}