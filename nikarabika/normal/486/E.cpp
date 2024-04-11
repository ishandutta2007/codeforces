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

const int maxn = 1e5;
int a[maxn],
	dp[maxn],
	agab[maxn],
	jolo[maxn],
	cnt[maxn];
bool ty[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	memset(dp, 63, sizeof dp);
	for(int i = 0; i < n; i++){
		agab[i] = lower_bound(dp, dp + n, a[i]) - dp;
		dp[agab[i]] = a[i];
		a[i] *= -1;
	}
	memset(dp, 63, sizeof dp);
	for(int i = n - 1; i >= 0; i--){
		jolo[i] = lower_bound(dp, dp + n, a[i]) - dp;
		dp[jolo[i]] = a[i];
	}
	int lis = 0;
	for(int i = 0; i < n; i++)
		smax(lis, agab[i] + 1);
	for(int i = 0; i < n; i++){
		if(agab[i] + jolo[i] + 1 != lis)
			ty[i] = 1;
		else
			cnt[agab[i]]++;
	}
	for(int i = 0; i < n; i++){
		if(ty[i] == 1)
			cout << 1;
		else if(cnt[agab[i]] - 1)
			cout << 2;
		else
			cout << 3;
	}
	cout << endl;
	return 0;
}