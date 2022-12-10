//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

#define sz(x) ((int)(x).size())
#define PB push_back

const int maxn = 1e5 + 85 - 69, maxm = 100 + 10;
LL dp[maxn][maxm], P[maxm];
LL n, m;
vector<int> cnt, cnt2;
vector<vector<int> > all;

void input(void){
	string s;
	cin >> s >> m;
	n = sz(s);
	for(int i = 0; i < n; i++)
		cnt[s[i] - '0']++;
	return;
}

void build(int pos = 0){
	if(pos == 10){
		all.PB(cnt2);
		return;
	}
	for(int i = 0; i <= cnt[pos]; i++){
		cnt2[pos] = i;
		build(pos + 1);
	}
	return;
}

inline int idof(vector<int> &v){
	return lower_bound(all.begin(), all.end(), v) - all.begin();
}

inline int fix(int rem){
	return ((rem % m) + m) % m;
}

LL DP(int pos = n, int rem = 0){
	int id = idof(cnt2);
	if(dp[id][rem] != -1)
		return dp[id][rem];
	if(pos == 0)
		return dp[id][rem] = (rem == 0);
	dp[id][rem] = 0;
	for(int i = (pos == n); i < 10; i++) if(cnt2[i]){
		cnt2[i]--;
		dp[id][rem] += DP(pos - 1, fix(rem - i * P[pos - 1]));
		cnt2[i]++;
	}
	return dp[id][rem];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cnt.resize(10, 0);
	cnt2 = cnt;
	input();
	build();
	sort(all.begin(), all.end());
	P[0] = 1;
	for(int i = 1; i < 100; i++)
		P[i] = fix(P[i - 1] * 10);
	memset(dp, -1, sizeof dp);
	cout << DP() << endl;
	return 0;
}