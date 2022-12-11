#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)3e5 + 1234;
int tt[N];

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  for(int i = 1;i <= n; i ++ )
    for(int j = 2;j * i <= n ; j ++ )
        tt[i * j] ++ ;
  int tot = 0;
  for(int i = 1;i <= n; i ++ )
    tot += tt[i];
  if(tot < k ){
    cout << "No\n";
    return 0; 
  }
  while(n > 1 and tot - tt[n] >= k){
    tot -= tt[n];
    --n;
  }
  tot -= k;
  cout << "Yes\n";
  set<int>ans;
  for(int i = 1;i <= n; i ++ )
    ans.insert(i);
  map<int,vector<int>> ct;
  for(int i = 1 ;i <= n; i ++)
    if(tt[i] == 1)
      ct[n / i].push_back(i);
  int cx;
  while(tot > 0){
    auto it = ct.upper_bound(tot);
    -- it;
    cx = it -> fi;
    tot -= cx;
    ans.erase(ct[cx].back());
    ct[cx].pop_back();
    if(ct[cx].empty())
      ct.erase(cx);
  }
  cout << ans.size() << "\n";
  for(auto x : ans)
  cout << x << " "; 
  return 0;
}