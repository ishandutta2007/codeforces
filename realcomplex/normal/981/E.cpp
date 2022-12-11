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

const int N = 10005;
const ll MOD = 1171470407;
ll dp[N];
vector<pii>L[N];

void add(int x){
  for(int i = N - 1 -x;i >= 0;i --){
    dp[i + x] += dp[i];
    dp[i + x] %= MOD;
  }
}

void rem(int x){
  for(int i = x;i < N;i ++ ){
    dp[i] -= dp[i - x];
    dp[i] += MOD;
    dp[i] %= MOD;
  }
}

bool rz[N];

int main(){
  fastIO;
  int n,q;
  cin >> n >> q;
  dp[0] = 1;
  int li,ri,xi;
  for(int i = 0;i < q;i ++ ){
    cin >> li >> ri >> xi;
    L[li].push_back(mp(xi, 1));
    L[ri + 1].push_back(mp(xi, -1));
  }
  for(int i = 1;i <= n;i ++ ){
    for(auto x : L[i]){
      if(x.se == 1){
        add(x.fi);
      }
      else{
        rem(x.fi);
      }
    }
    for(int j = 1;j <= n;j ++ )
      if(dp[j] > 0)
        rz[j] = true;
    
  }
  vector<int>ans;
  for(int i = 1;i <= n;i ++ )
    if(rz[i])
      ans.push_back(i);
  cout << ans.size() << "\n";
  for(auto x : ans)
    cout << x << " " ;
  return 0;
}