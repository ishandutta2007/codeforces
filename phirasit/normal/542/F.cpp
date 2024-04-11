#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

const int MAX_T = 110;
const int N = 1010;

vector<int> data[MAX_T];

int s[N], sum[N];

int dp[MAX_T][N];
int n, T;

int main() {

  ios::sync_with_stdio( false );
  cin >> n >> T;
  for ( int i = 0 ; i < n ; i++ ) {
    int t, q;
    cin >> t >> q;
    data[t].push_back(q);
  }

  for ( int i = 1 ; i <= T ; i++ ) {

    sort( data[i].begin(), data[i].end(), greater<int>() );
    s[i] = s[i-1] + data[i].size();

    sum[0] = 0;
    for ( int j = 1 ; j <= data[i].size() ; j++ ) {
      sum[j] = sum[j-1] + data[i][j-1];
    }

    for ( int j = 0 ; j <= s[i] ; j++ ) {
      dp[i][j] = 0;
      for ( int k = 0 ; k <= data[i].size() and k <= j ; k++ ) {
        int val = sum[k] + dp[i-1][ min( s[i-1], 2 * (j-k) ) ];
        dp[i][j] = max( dp[i][j], val );
      }
    }
  }

  cout << dp[T][1] << endl;

  return 0;
}