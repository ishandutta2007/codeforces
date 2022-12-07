#include <bits/stdc++.h>

using namespace std;

const int N = 15;

char arr[N][N];
bool col[N];

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
  #endif // ONLINE_JUDGE
  int tt; cin >> tt;
  while(tt--){
    string s; cin >> s;
    vector < pair < int, int > > ans;
    for(int i = 1; i <= 12; ++i){
      if(12 % i == 0){
        memset(col, 0, sizeof col);
        int n = i, m = 12 / i;
        for(int u = 1; u <= n; ++u){
          for(int v = 1; v <= m; ++v){
            arr[u][v] = s[m * (u - 1) + v - 1];
            if(arr[u][v] == 'O'){
              col[v] = 1;
            }
          }
        }
        for(int j = 1; j <= m; ++j){
          if(col[j] == 0){
            ans.push_back(make_pair(n, m));
            break;
          }
        }
      }
    }
    cout << ans.size() << " ";
    for(int i = 0; i < ans.size(); ++i){
      cout << ans[i].first << "x" << ans[i].second << " ";
    }
    cout << endl;
  }
  return 0;
}