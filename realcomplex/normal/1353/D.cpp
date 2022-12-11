#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
vector<int> T[N];
int ans[N];

void solve(){
  int n;
  cin >> n;
  for(int i = 0 ; i <= n; i ++ ){
    T[i].clear();
    ans[i]=-1;
  }
  
  T[n].push_back(1);
  int op = 1;
  int mid;
  int lef, rig;
  for(int i = n; i >= 1; i -- ){
    sort(T[i].begin(), T[i].end());
    for(auto x : T[i]){
      lef = x;
      rig = x + i - 1;
      if(i % 2 == 1){
        mid = (lef + rig) / 2;
      }
      else{
        mid = (lef + rig - 1) / 2;
      }
      ans[mid] = op;
      T[mid-lef].push_back(lef);
      T[rig-mid].push_back(mid + 1);
      op ++ ;
    }
  }
  for(int i = 1; i <= n; i ++ ){
    cout << ans[i] << " "; 
  }
  cout << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc;t ++ )
    solve();
  return 0;
}