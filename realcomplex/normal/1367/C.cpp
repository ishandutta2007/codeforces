#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    int n, k;
    cin >> n >> k;
    vector<int> rig(n);
    vector<char> in(n);
    for(int i = 0 ; i < n; i ++ )
      cin >> in[i];
    rig[n - 1] = (int)1e9;
    for(int i = n - 1; i >= 0 ; i -- ){
      if(i + 1 < n) rig[i]=rig[i + 1];
      if(in[i] == '1') rig[i] = i;
    }
    int cnt = (int)1e9;
    int ans = 0;
    for(int i = 0 ; i < n; i ++ ){
      if(in[i] == '1'){
        cnt = 0;
      }
      else if(in[i] == '0'){
        cnt ++ ;
        if(rig[i] - i > k && cnt > k){
          ans ++ ;
          cnt=0;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}