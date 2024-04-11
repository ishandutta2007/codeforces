#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
 
#define p 1000000007
 
using namespace std;
 
typedef long long ll;
 
bool dp[100100];
int main(){
	int n, d, e;
	cin >> n >> d >> e;
	e *= 5;
	int l = d * e / __gcd(d, e);
	if(n / l >= 1){
		n = n % l + l;
	}
	fill(dp, dp+100100, 0);
	dp[n] = 1;
	int ans = n;
	for(int i=n-1;i>=0;i--){
		if(dp[i + d] || dp[i + e]){
			dp[i] = 1;
			ans = i;
		}else{
		    dp[i] = 0;
		}
	}
	cout << ans;
	return 0;
}