//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//Man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;
typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

const int maxn = 2e5 + 10;
const LL Mod = 1000LL * 1000 * 1000LL + 7;
LL dp_base[maxn], sum_base[maxn];
LL *dp, *sum;
int n, m;
pii bus[maxn];
vector<int> all;

bool cmp(pii x, pii y){
	return x.R < y.R;
}

LL upd(int id){
	return (sum[id] != 0) ? sum[id] : sum[id] = upd(id - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dp = dp_base + 1;
	sum = sum_base + 1;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> bus[i].L >> bus[i].R;
		all.PB(bus[i].L);
		all.PB(bus[i].R);
	}
	all.PB(0);
	all.PB(n);
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	sort(bus, bus + m, cmp);
	dp[0] = 1;
	sum[0] = 1;
	for(int i = 0; i < m; i++){
		int id1 = lower_bound(all.begin(), all.end(), bus[i].L) - all.begin();
		int id2 = lower_bound(all.begin(), all.end(), bus[i].R) - all.begin();
		if((i == 0 and bus[i].R != 0) or bus[i].R != bus[i - 1].R)
			upd(id2);
		dp[id2] += sum[id2 - 1] - sum[id1 - 1];
		dp[id2] %= Mod;
		sum[id2] += sum[id2 - 1] - sum[id1 - 1];
		sum[id2] %= Mod;
	}
	cout << (dp[sz(all) - 1] + Mod) % Mod << endl;
	return 0;
}