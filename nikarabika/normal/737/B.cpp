//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 2e5 + 85 - 69;
int dp[maxn];
string s;
int n, a, b, k;
vector<int> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b >> k
		>> s;
	s += '1', n++;
	int cur = 0;
	int rem = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0') cur++;
		else{
			rem += cur / b;
			cur = 0;
		}
	}
	dp[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--)
		dp[i] = (1 - s[i] + '0') * (dp[i + 1] + 1);
	for(int i = 0; i < n and rem >= a; i++){
		int len = dp[i];
		if(len < b) continue;
		rem--;
		s[i + b - 1] = '1';
		ans.PB(i + b);
		i = i + b - 1;
	}
	cout << sz(ans) << '\n';
	for(auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}