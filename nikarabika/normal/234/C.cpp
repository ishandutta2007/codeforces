#include <bits/stdc++.h>

#define cin fin
#define cout fout

using namespace std;

const int maxn = 1e5 + 10;
int dp[maxn], t[maxn], n;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		dp[i] = dp[i - 1] + (t[i] >= 0);
	}
	int pd = 0, ans = 1e9;
	for(int i = n; i > 1; i--){
		pd += t[i] <= 0;
		ans = min(ans, pd + dp[i - 1]);
	}
	cout << ans << endl;
	return 0;
}