#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define L first
#define R second

const int maxn = 5e3 + 10;
int dp[maxn], par[maxn];
pair<pair<int, int>, int> a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, w, h;
	cin >> n >> w >> h;
	for(int i = 1; i <= n; i++){
		cin >> a[i].L.L >> a[i].L.R;
		a[i].R = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		if(w < a[i].L.L and h < a[i].L.R) dp[i] = 1;
		else continue;
		par[i] = 0;
		for(int j = i - 1; j > 0; j--) if(dp[j] != 0 and dp[j] + 1 > dp[i] and a[j].L.L < a[i].L.L and a[j].L.R < a[i].L.R){
			dp[i] = dp[j] + 1;
			par[i] = j;
		}
	}
	int Max = 0, Maxi = 0;
	for(int i = 1; i <= n; i++)
		if(dp[i] > Max)
			Max = dp[i], Maxi = i;
	vector<int> ans;
	while(Maxi != 0)
		ans.PB(a[Maxi].R), Maxi = par[Maxi];
	cout << ans.size() << endl;
	for(int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}