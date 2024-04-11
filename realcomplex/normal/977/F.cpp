#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)2e5 + 1234;
map<int,int>las;
int dp[N];
int fr[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int x;
  int ix;
  for(int i =1 ;i <= n;i ++ ){
    cin >> x;
    dp[i] = 1;
    fr[i] = i;
    if(!las[x - 1] == 0){
      ix = las[x - 1];
      if(dp[ix] + 1 > dp[i]){
        dp[i] = dp[ix] + 1;
        fr[i] = ix;
      }
    }
    las[x] = i;
  }
  int ans = 0;
  for(int i = 1; i <= n;i ++ ){
    if(dp[i] > ans){
      ans = dp[i];
      ix = i;
    }
  }
  vector<int>tp;
  tp.push_back(ix);
  while(ix != fr[ix]){
    ix = fr[ix];
    tp.push_back(ix);
  }
  cout << ans << "\n";
  reverse(tp.begin(),tp.end());
  for(auto x : tp)
    cout << x << " ";
  cout << "\n";
  return 0;
}