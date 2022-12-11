#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int tt = 0 ; tt < tc; tt ++ ){
    string p, h;
    cin >> p >> h;
    int n = p.size();
    int m = h.size();
    vector<int> c(26,0);
    for(auto x : p){
      c[x - 'a'] ++ ;
    }
    bool ans = false;
    vector<int> pp;
    bool ok;
    for(int i = 0 ; i < m ; i ++ ){
      if(i + n - 1 < m){
        pp.resize(26);
        for(int j = 0 ; j < 26; j ++ )
          pp[j] = 0;
        for(int j = 0 ; j < n; j ++ ){
          pp[h[i + j] - 'a'] ++ ;
        }
        ok = true;
        for(int j = 0 ; j < 26; j ++ ){
          if(c[j] != pp[j])
            ok = false;
        }
        if(ok)
          ans = true;
      }
    }
    if(ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}