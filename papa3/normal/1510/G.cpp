#include <bits/stdc++.h>

using namespace std;
vector<int> kra[10002];
vector<pair<int, int> > wyn;

int dp[102][102];
int odz[102][102][102];
pair<int, int> odz_np[102][102][102];
int dp_np[102][102];
int ndp[102];
int ndp_np[102];
int wiel[102];

void odzysk(int n, int ile, int specstart = -1) {
	if (specstart == -1)
		specstart = kra[n].size();
	cout << n << " ";
	for (int i = specstart; i>0; i--) {
		int v = kra[n][i-1];
		if (odz[n][ile][i] == 0)
			continue;
		odzysk(v, odz[n][ile][i]);
		ile -= odz[n][ile][i];
		cout << n << " ";
	}
}

void odzysk_np(int n, int ile) {
	if (ile == 1) {
		cout << n << " ";
		return;
	}
	for (int i = kra[n].size(); i>0; i--) {
		int v = kra[n][i-1];
		if (odz_np[n][ile][i].first == 0)
			continue;
		if (odz_np[n][ile][i].second == 1) {
			odzysk(n, ile - odz_np[n][ile][i].first, i - 1);
			odzysk_np(v, odz_np[n][ile][i].first);
			return;
		}
		cout << n << " ";
		odzysk(v, odz_np[n][ile][i].first);
		ile -= odz_np[n][ile][i].first;
	}
}

void dfs(int n) {
	for (int i=2; i<=100; i++) {
		dp[n][i] = 1000000001;
		dp_np[n][i] = 1000000001;
	}
	dp[n][1] = 0;
	dp_np[n][1] = 0;
	int aktwiel = 1, ktory = 1;
	
	for (auto v : kra[n]) {
		dfs(v);
		
		for (int i=0; i<=aktwiel+wiel[v]; i++) {
			ndp[i] = 1000000001;
			ndp_np[i] = 1000000001;
			odz[n][i][ktory] = 0;
			odz_np[n][i][ktory] = {0, 0};
		}
		for (int wn = 1; wn <= aktwiel; wn++) {
			for (int wv = 1; wv <= wiel[v]; wv++) {
				if (dp[n][wn]+dp[v][wv]+2 < ndp[wn+wv]) {
					ndp[wn+wv] = dp[n][wn]+dp[v][wv]+2;
					odz[n][wn + wv][ktory] = wv;
				}
				
				if (min(dp_np[n][wn]+dp[v][wv]+2, dp[n][wn]+dp_np[v][wv]+1) < ndp_np[wn+wv]) {
					if (dp_np[n][wn]+dp[v][wv]+2 < dp[n][wn]+dp_np[v][wv]+1) {
						ndp_np[wn+wv] = dp_np[n][wn]+dp[v][wv]+2;
						odz_np[n][wn + wv][ktory] = {wv, 0};
					} else {
						ndp_np[wn+wv] = dp[n][wn]+dp_np[v][wv]+1;
						odz_np[n][wn + wv][ktory] = {wv, 1};
					}
				}
			}
		}
		for (int i=0; i<=aktwiel+wiel[v]; i++) {
			if (dp[n][i] <= ndp[i])
				odz[n][i][ktory] = 0;
			dp[n][i] = min(dp[n][i], ndp[i]);
			
			if (dp_np[n][i] <= ndp_np[i])
				odz_np[n][i][ktory] = {0, 0};
			dp_np[n][i] = min(dp_np[n][i], ndp_np[i]);
		}
		
		aktwiel += wiel[v];
		ktory++;
	}
	wiel[n] = aktwiel;
	//cout << n << " " << dp_np[n][aktwiel] << " " << dp[n][aktwiel] << "\n";
}

void fun() {
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		kra[i].clear();
	}
	for (int i=2; i<=n; i++) {
		int o;
		cin >> o;
		kra[o].push_back(i);
	}
	dfs(1);
	cout << dp_np[1][k] << "\n";
	odzysk_np(1, k);
	cout << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) fun();
}

/*
3                                    
6 2
1 1 2 2 3
6 6
1 1 2 2 3
6 4
1 2 3 4 5
*/