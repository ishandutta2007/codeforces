#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

const int N = 51;
const int BITS = 60;
const int K = 51;

bool dp[N][K];
ll A[N];
int n,k;

bool can_mask(ll mask){
  memset(dp, false, sizeof dp);
  dp[0][0] = true;
  ll sz;
  for(int i = 1;i <= n;i ++ ){
    sz = 0;
    for(int j = i;j <= n;j ++ ){
      sz += A[j];
      if((sz & mask) >= mask){
        for(int x = 1; x <= k; x ++ ){
          if(dp[i - 1][x - 1] == true)
            dp[j][x] = true;
        }
      }
    }
  }
  return dp[n][k];
}

int main(){
  fastIO;
  cin >> n >> k;
  for(int i = 1;i <= n;i ++ )
    cin >> A[i];
  ll mask = 0;
  ll temp;
  for(int j = BITS - 1;j >= 0;j -- ){
    temp = (mask | (1LL << j));
    if(can_mask(temp))
      mask = temp;
  }
  cout << mask << "\n";
  return 0;
}