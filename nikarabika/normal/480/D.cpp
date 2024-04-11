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

const int maxn = 505, maxs = 1005;
int dp[maxn][maxs],
	tdp[maxn],
	func[maxn],
	in[maxn],
	out[maxn],
	ord[maxn],
	s[maxn],
	w[maxn],
	v[maxn];
int n;

bool cmp(int i, int j){
	return in[i] != in[j] ? in[i] < in[j] : out[i] > out[j];
}

int find_posit(int x){
	int lo = -1,
		hi = n;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(in[ord[mid]] >= x)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int calc_dp(int id, int sth){
	memset(tdp, 0, sizeof tdp);
	for(int i = n - 1; i > id; i--)
		if(in[ord[i]] >= in[ord[id]] and out[ord[i]] <= out[ord[id]])
			tdp[i] = max(tdp[i + 1], tdp[func[ord[i]]] + dp[i][sth]);
		else
			tdp[i] = tdp[i + 1];
	return tdp[id + 1];
}

void calc_dp(void){
	for(int st = 0; st <= s[n - 1]; st++)
		for(int i = n - 1; i >= 0; i--)
			if(st >= w[ord[i]])
				dp[i][st] = v[ord[i]] + calc_dp(i, min(s[ord[i]], st - w[ord[i]]));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s[n];
	for(int i = 0; i < n; i++)
		cin >> in[i] >> out[i] >> w[i] >> s[i] >> v[i], ord[i] = i;
	ord[n] = n;
	out[n] = 2 * n;
	n++;
	sort(ord, ord + n, cmp);
	for(int i = 0; i < n; i++)
		func[i] = find_posit(out[i]);
	calc_dp();
	cout << dp[0][s[n - 1]] << endl;
	return 0;
}