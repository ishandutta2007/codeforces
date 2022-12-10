    //sobskdrbhvk
    //remember...
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
    #define smin(x, y) (x) = min((x), (y))
    #define smax(x, y) (x) = max((x), (y))
    #define sz(x) ((int)(x).size())
    #define all(x) (x).begin(),(x).end()
     
    const int maxn = 2e5;
    int dp[maxn][10],
    	par[maxn][10];
    string s;
    int go[10][1000];
     
    int solve() {
    	cin >> s;
    	for (int j = 0; j < 7; j++)
    		dp[0][j] = -1e9;
    	dp[0][0] = 0;
    	for (int i = 0; i < sz(s); i++) {
    		for (int j = 0; j < 7; j++) {
    			dp[i + 1][j] = dp[i][j];
    			par[i + 1][j] = -1;
    		}
    		for (int j = 0; j < 7; j++) if (j != 3 and j != 6) {
    			int &d = dp[i + 1][go[j][s[i]]];
    			int &p = par[i + 1][go[j][s[i]]];
    			if (dp[i][j] + 1 > d) {
    				d = dp[i][j] + 1;
    				p = j;
    			}
    		}
    	}
    	int mx = dp[sz(s)][0];
    	int pos = 0;
    	vector<int> ans;
    	for (int j = 1; j < 7; j++)
    		if (j % 3) {
    			if (dp[sz(s)][j] > mx) {
    				pos = j;
    				mx = dp[sz(s)][j];
    			}
    		}
    	for (int i = sz(s); i > 0; i--) {
    		if (par[i][pos] == -1)
    			ans.PB(i);
    		else
    			pos = par[i][pos];
    	}
    	cout << sz(ans) << '\n';
    	reverse(all(ans));
    	for (int x : ans)
    		cout << x << ' ';
    	cout << '\n';
    }
     
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0); cout.tie(0);
    	go[0]['t'] = 4;
    	go[0]['o'] = 1;
     
    	go[1]['n'] = 2;
    	go[1]['t'] = 4;
    	go[1]['o'] = 1;
    	
    	go[2]['e'] = 3;
    	go[2]['t'] = 4;
    	go[2]['o'] = 1;
    	
    	go[4]['w'] = 5;
    	go[4]['t'] = 4;
    	go[4]['o'] = 1;
    	
    	go[5]['o'] = 6;
    	go[5]['t'] = 4;
    	
    	int q;
    	cin >> q;
    	while (q--)
    		solve();
    	return 0;
    }