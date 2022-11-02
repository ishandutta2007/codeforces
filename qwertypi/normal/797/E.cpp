#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
#define p1 1000000007

using namespace std;
typedef long long ll;

int A[100002]; // sol'n for O(n lg n)
int dp[317][100002]; // value of k, dp on op
int main(){
	int n;
	cin >> n;
	int sq = floor(sqrt(n));
	for(int i=0;i<n;i++){
		cin >> A[i]; 
	}
	for(int i=1;i<=sq;i++){
		dp[i][n+1] = 0;
	}
	for(int i=1;i<=sq;i++){ // value of k
		for(int j=n;j>=1;j--){
			dp[i][j] = dp[i][min(n+1, j + A[j-1] + i)] + 1;
		}
	}
	
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int p, k;
		cin >> p >> k;
		if(k <= sq){
			cout << dp[k][p] << endl;
		}else{
			int res = 0;
			int curInt = p;
			while(curInt <= n){
				curInt = curInt + A[curInt-1] + k;
				res++;
			}
			cout << res << endl;
		}
	}
	return 0;
}