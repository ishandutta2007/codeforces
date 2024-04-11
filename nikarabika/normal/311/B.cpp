//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 1e5 + 85 - 69;
vector<LL> tim;
LL sum[maxn],
   d[maxn],
   dp[2][maxn],
   badval,
   stc[maxn];
int n, m, p, cur, pre, ptr, sz;

LD inters(int id1, int id2){
	LD b1 = sum[id1 + 1] + dp[pre][id1], b2 = sum[id2 + 1] + dp[pre][id2];
	return (b1 - b2) / (id1 - id2);
}

void add(int id){
	while(sz >= 2 and inters(stc[sz - 1], stc[sz - 2]) > inters(stc[sz - 1], id))
		sz--;
	if(sz <= ptr) ptr = sz;
	stc[sz++] = id;
	return;
}

LL get(LL pos){
	LD tmp = pos;
	while(ptr + 1 < sz and inters(stc[ptr], stc[ptr + 1]) < tmp)
		ptr++;
	while(ptr and inters(stc[ptr], stc[ptr - 1]) > tmp)
		ptr--;
	LL id = stc[ptr];
	return -id * pos + (sum[id + 1] + dp[pre][id]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> p;
	for(int i = 1; i < n; i++){
		cin >> d[i];
		d[i] += d[i - 1];
	}
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--;
		se -= d[fi];
		tim.PB(se);
	}
	sort(all(tim));
	for(int i = 0; i < sz(tim); i++)
		sum[i + 1] = sum[i] + tim[i];
	memset(dp, 63, sizeof dp);
	cur = 0, pre = 1;
	for(int i = 1; i <= p; i++){
		swap(pre, cur);
		memset(dp[cur], 63, sizeof dp[cur]);
		ptr = sz = 0;
		for(int j = 0; j < sz(tim); j++){
			dp[cur][j] = (j + 1) * tim[j] - sum[j + 1];
			add(j);
			smin(dp[cur][j], j * tim[j] - sum[j + 1] + get(tim[j]));
		}
	}
	cout << dp[cur][sz(tim) - 1] << '\n';
	return 0;
}