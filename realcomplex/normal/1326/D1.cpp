#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5005;
bool is[N][N];
int ch[N];

void solve(){
  string s;
  cin >> s;
  int x;
  ch[0] = 0;
  for(int i = 0 ; i < s.size(); i ++ ){
    x = s[i] - 'a';
    ch[i + 1] = x;
  }
  int n = s.size();
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      is[i][j]=false;
    }
  }
  ch[n + 1] = 0;
  for(int i = 1; i <= n; i ++ )
    is[i][i] = true;
  for(int i = 1; i < n; i ++ ){
    if(ch[i]==ch[i+1])
      is[i][i+1]=true;
  }
  int l, r;
  for(int sz = 3; sz <= n; sz ++ ){
    for(int i = 1; i + sz - 1 <= n; i ++ ){
      l = i;
      r = i + sz - 1;
      is[l][r] = (is[l+1][r-1] & (ch[l] == ch[r]));
    }
  }
  pii sol = mp(1,0);
  int sa = 0, sb = 0;
  for(int i = 0 ; i <= n; i ++ ){
    if(ch[i] == ch[n - i + 1] && i < n - i + 1){
      sa = i, sb = i;
      if(sa + sb > sol.fi + sol.se){
        sol = mp(sa, sb);
      }
      for(int j = i + 1; j <= n - i; j ++ ){
        sa ++ ;
        if(is[i + 1][j]){
          if(sol.fi + sol.se < sa + sb){
            sol = mp(sa,sb);
          }
        }
      }
      
      sa = i;
      sb = i;
      for(int j = n - i ; j > i ; j -- ){
        sb ++ ;
        if(is[j][n-i]){
          if(sol.fi + sol.se < sa + sb){
            sol = mp(sa,sb);
          }
        }
      }
    }
    else{
      break;
    }
  }
  for(int i = 1; i <= sol.fi ; i ++ )
    cout << char(ch[i]+'a');
  for(int i = sol.se - 1 ; i >= 0; i -- )
    cout << char(ch[n - i]+'a');
  cout << "\n";
}
int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 0 ; i < tc; i ++ )
    solve();
  return 0;
}