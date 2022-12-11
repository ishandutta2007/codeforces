#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 505;

int a[N];
int b[N];

int dp[N];
int pv[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 1; i <=n; i ++ ){
		cin >> a[i];
	}
	int m;
	cin >> m;
	for(int i = 1; i <= m ; i ++ ){
		cin >> b[i];
	}
	int k;
	for(int i = 1; i <= n; i ++ ){
		k = 0;
		for(int j = 1; j <= m ; j ++ ){
			if(a[i] == b[j]){
				if(dp[j] < dp[k] + 1){
					dp[j] = dp[k] + 1;
					pv[j] = k;
				}
			}
			else if(b[j] < a[i]){
				if(dp[j] > dp[k]){
					k = j;
				}
			}
		}
	}
	int d = 0;
	for(int i = 1; i <= m; i ++ ){
		if(dp[i] > dp[d])
			d = i;
	}
	vector<int> ans;
	while(d != 0){
		ans.push_back(b[d]);
		d = pv[d];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(auto x : ans)
		cout << x << " ";
	return 0;
}