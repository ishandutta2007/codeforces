#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
multiset<char>mod[N];

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ; t < tc; t ++ ){
    int n, k;
    cin >> n >> k;
    char q;
    for(int j = 0 ; j < k; j ++ )
      mod[j].clear();
    for(int i = 0 ; i < n; i ++ ){
      cin >> q;
      mod[i%k].insert(q);
    }
    int ans = 0;
    int tr;
    for(int i = 0 ; i < k ; i ++ ){
      if(i <= k - i - 1){
        int cur = mod[i].size() + mod[k-i-1].size();
        for(char y = 'a' ; y <= 'z'; y ++ ){
          tr = 0;
          for(auto v : mod[i])
            tr += (v != y);
          if(i != k - i -1){
            for(auto v : mod[k - i - 1])
              tr += (v != y);
          }
          cur = min(cur, tr);
        }
        ans += cur;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}