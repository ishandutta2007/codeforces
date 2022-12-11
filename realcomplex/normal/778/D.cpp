#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 52;
char cur[N][N];
char obt[N][N];
int n, m;

void flip(int i, int j){ // we assume that we can flip
  if(cur[i][j] == 'L' || cur[i][j] == 'R'){
    cur[i][j] = 'U';
    cur[i][j + 1] = 'U';
    cur[i+1][j] = 'D';
    cur[i+1][j+1] = 'D';
  }
  else{
    cur[i][j] = 'L';
    cur[i][j+1] = 'R';
    cur[i+1][j] = 'L';
    cur[i+1][j+1] = 'R';
  }
}

vector<pii> solve(){
  if(m % 2 == 0){
    int x, y;
    vector<pii> sol;
    for(int i = 1; i <= n; i ++ ){
      for(int j = 1; j <= m; j ++ ){
        if(cur[i][j] == 'U'){
          x = i;
          y = j;
          while(cur[x][y] == 'U'){
            if(cur[x][y + 1] == 'U'){
              sol.push_back(mp(x,y));
              flip(x,y);
              while(x != i || y != j){
                x--;
                y--;
                sol.push_back(mp(x,y+1));
                flip(x,y+1);
                sol.push_back(mp(x,y));
                flip(x,y);
              }
              break;
            }
            else if(cur[x][y + 1] == 'L' && cur[x + 1][y + 1] == 'L'){
              do{
                sol.push_back(mp(x,y+1));
                flip(x,y+1);
                sol.push_back(mp(x,y));
                flip(x,y);
                x--;
                y--;
              }while(x >= i || y >= j);
              break;
            }
            else{
              x ++ ;
              y ++ ;
            }
          }
        }
      }
    }
    return sol;
  }
  else{
    int x, y;
    vector<pii> sol;
    for(int j = 1; j <= m; j ++ ){
      for(int i = 1; i <= n; i ++ ){
        if(cur[i][j] == 'L'){
          x = i;
          y = j;
          while(cur[x][y] == 'L'){
            if(cur[x + 1][y] == 'L'){
              sol.push_back(mp(x,y));
              flip(x,y);
              while(x != i || y != j){
                x--;
                y--;
                sol.push_back(mp(x + 1,y));
                flip(x + 1, y);
                sol.push_back(mp(x,y));
                flip(x,y);
              }
              break;
            }
            else if(cur[x + 1][y] == 'U' && cur[x + 1][y + 1] == 'U'){
              do{
                sol.push_back(mp(x + 1,y));
                flip(x + 1, y);
                sol.push_back(mp(x,y));
                flip(x, y);
                x--;
                y--;
              }while(x >= i || y >= j);
              break;
            }
            else{
              x ++ ;
              y ++ ;
            }
          }
        }
      }
    }
    return sol;
  }
}

int main(){
  fastIO;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ )
       cin >> cur[i][j];
  }
  vector<pii> s1 = solve();
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> cur[i][j];
    }
  }
  vector<pii> s2 = solve();
  reverse(s2.begin(), s2.end());
  cout << s1.size() + s2.size() << "\n";
  for(auto x : s1)
    cout << x.fi << " " << x.se << "\n";
  for(auto x : s2)
    cout << x.fi << " " << x.se << "\n";
  return 0;
}