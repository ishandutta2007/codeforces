#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define sz(a) ((int) a.size())
#define vi vector<int>
#define ll long long
#define me(f, x) memset(f, x, sizeof(f))  
using namespace std;
const int N = 2e5 + 7;
int n, m, su[N], sv[N];
int pl, pr, nxt[N];
int dp[N][2]; // 01; 10
bool ok[N];
int cnt[4], dnt[4];
vi re[N];
void Main () {
	me(ok, 0);
	cin >> n >> m;
	L(i, 2, n) re[i].clear (), re[i].push_back(0);
	re[n + 1].clear ();
	L(i, 1, n - 1) re[n + 1].push_back(i);
	L(i, 1, m) {
		cin >> su[i] >> sv[i];
		if(sv[i] == su[i] + 1) 
			ok[su[i]] = true;	
		else 
			re[sv[i]].push_back(su[i]);
	}
	L(i, 1, n - 1) if(!ok[i]) pr = i + 1;
	R(i, n, 1) if(!ok[i]) pl = i;
	R(i, n, 1) 
		nxt[i] = ok[i] ? nxt[i + 1] : i;
	if(pl == n) 
		return cout << (ll) n * (n - 1) / 2 << '\n', void ();
	me (dp, 0);
	dp[pl + 1][0] = 1;
	dp[pl + 1][1] = 2;
	L(j, pl + 2, n + 1) 
		for (const int &t : re[j]) 
			L(o, 0, 1) if(nxt[t + 1] >= j - 1)  
				dp[j][o] |= dp[t + 1][o ^ 1];
	R(j, pl + 1, 1) 
		for (const int &t : re[j]) 
			L(o, 0, 1) if(nxt[t + 1] >= j - 1)  
				dp[t + 1][o ^ 1] |= dp[j][o];
	me(cnt, 0), me(dnt, 0);
	L(i, pr, n + 1) 
		cnt[dp[i][0]] += 1;
	L(i, 1, pl + 1) 
		dnt[dp[i][0]] += 1;
	
	ll ns = 0;
	L(i, 0, 3) 
		L(j, 0, 3) 
			if(i & j) 
				ns += (ll) cnt[i] * dnt[j];
	if(pl + 1 == pr) 
		ns -= 1; 

	cout << ns << '\n';
}


int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}