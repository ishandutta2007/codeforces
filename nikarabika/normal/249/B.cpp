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

const int maxn = 5e5 + 85 - 69,
	  maxl = 22;
string s;
int spt[maxl][maxn],
	pp[maxn],
	hcnt[maxn],
	scnt[maxn],
	cnt[maxn],
	func[maxn],
	dp[maxn],
	n, lasth, t;

int merge(int i, int j){
	return cnt[i] < cnt[j] ? i : j;
}

int get(int le, int ri){
	int f = pp[ri - le + 1];
	return merge(spt[f][le], spt[f][ri - (1 << f) + 1]);
}

void calc_func(void){
	pp[0] = -1;
	for(int i = 1; i < maxn; i++)
		pp[i] = pp[i>>1]+1;
	for(int i = 0; i <= n; i++)
		spt[0][i] = i;
	for(int i = 1; i < maxl; i++)
		for(int j = 0; j + (1 << i) <= n + 1; j++)
			spt[i][j] = merge(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);
	for(int i = 0; i < n; i++){
		int lo = i - 1,
			hi = n + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(cnt[get(i, mid)] - cnt[i] < 0)
				hi = mid;
			else
				lo = mid;
		}
		func[i] = lo;
	}
	return;
}

void calc_dp(void){
	calc_func();
	memset(dp, 63, sizeof dp);
	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		if(hcnt[n] - hcnt[i] > scnt[n] - scnt[i]) continue;
		if(hcnt[n] - hcnt[i] == 0){ dp[i] = 0; continue;}
		int id = max(lasth, lower_bound(scnt, scnt + n + 1, (hcnt[n] - hcnt[i]) + scnt[i]) - scnt - 1);
		//cout << i << ": " << id << endl;
		if(func[i] > id){ dp[i] = lasth - i + 1; continue;}
		dp[i] = (id - i + 1) + (id - func[i]);
	}
	return;
}

LL get(int have){
	int ret = 1000 * 1000 * 1000 * 1.5,
		cur = 0;
	int lst = -1;
	for(int i = 0; i < n; i++){
		if(have >= 0) smin(ret, cur + dp[i]);
		cur++;
		if(s[i] == 'H'){
			have--;
			if(have == -1)
				lst = i;
		}
		else if(s[i] == 'S'){
			have++;
			if(have == 0)
				cur += (i - lst) * 2;
		}
	}
	if(have >= 0) smin(ret, cur);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;
	cin >> s;
	while(s[n - 1] == '.') n--;
	for(int i = 0; i < n; i++){
		scnt[i + 1] = scnt[i] + (s[i] == 'S');
		hcnt[i + 1] = hcnt[i] + (s[i] == 'H');
		cnt[i + 1] = scnt[i + 1] - hcnt[i + 1];
		if(s[i] == 'H') lasth = i;
	}
	if(lasth + 1 > t){
		cout << -1 << endl;
		return 0;
	}
	calc_dp();
	/*for(int i = 0; i <= n; i++)
		cout << dp[i] << ' ';
	cout << endl;
	cout << get(1) << endl;
	return 0;*/
	int lo = max(-1, hcnt[n] - scnt[n] - 1),
		hi = hcnt[n] + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(get(mid) <= t)
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
	return 0;
}