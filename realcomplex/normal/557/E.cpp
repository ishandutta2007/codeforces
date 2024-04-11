#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5001;
bool dp[N][N];
int trie[N * N][2];
int cur[N * N];
int sum[N * N];
int cnt = 1;

void dfs(int node){
	sum[node] = cur[node];
	for(int t = 0; t < 2; t ++ )
		if(trie[node][t] != -1){
			dfs(trie[node][t]);
			sum[node] += sum[trie[node][t]];
		}
}

int main(){
	fastIO
	string t;
	cin >> t;
	int k;
	cin >> k;
	int n = t.size();
	for(int len = 1; len <= n; len ++ ){
		for(int j = 0; j < n; j ++ ){
			if(len <= 4){
				dp[j][j + len - 1] = (t[j] == t[j + len - 1]);
			}
			else{
				dp[j][j + len -  1] = (t[j] == t[j + len - 1] && dp[j + 2][j + len - 3]);
			}
		}
	}
	
	for(int i = 0 ; i < N * N; i ++ ){
		trie[i][0] = -1;
		trie[i][1] = -1;
	}
	int root = 0;
	for(int l = 0; l < n; l ++ ){
		root = 0;
		for(int r = l; r < n; r ++ ){
			if(trie[root][t[r] - 'a'] == -1)
				trie[root][t[r] - 'a'] = cnt ++ ;
			root = trie[root][t[r] - 'a'];
			if(dp[l][r])
				cur[root] ++ ;
				
		}
	}
	dfs(0);
	root = 0;
	while(k > 0){
		if(trie[root][0] != -1 && sum[trie[root][0]] >= k){
			cout << "a";
			root = trie[root][0];
			k -= cur[root];
		}
		else{
			cout << "b";
			k -= sum[trie[root][0]];
			root = trie[root][1];
			k -= cur[root];
		}
	}
	cout << "\n";
	return 0;
}