#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 7005;
int dg[N];
vector<int> R[N];
bool ok[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  ll a[n], b[n];
  for(int i = 0 ; i < n; i ++ ){
    cin >> a[i];
  }
  for(int i = 0 ; i < n; i ++ ){
    cin >> b[i];
  }
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ;j  < n; j ++ ){
      if(i != j){
        if((a[i] ^ a[j]) & a[i]){
          R[j].push_back(i);
          dg[i] ++ ;
        }
      }
    }
  }
  for(int i = 0 ; i < n ; i ++ )
    ok[i] = true;
  int sz = n-1;
  bool good = true;
  while(good){
    good = false;
    for(int i = 0 ; i < n ; i ++ ){
      if(dg[i] == sz){
        good = true;
        ok[i] = false;
        sz -- ;
        for(auto x : R[i])
          dg[x] -- ;
        continue;
      }
    }
  }
  ll ans = 0;
  for(int i = 0 ; i < n ; i ++ ){
    if(ok[i])
      ans += b[i];
  }
  cout << ans;
  return 0;
}