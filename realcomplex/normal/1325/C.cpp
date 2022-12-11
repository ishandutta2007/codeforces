#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];
int f[N];

int main(){ 
  fastIO;
  int n;
  cin >> n;
  int u, v;
  for(int i = 0; i < n-1; i ++ ){
    cin >> u >> v;
    T[u].push_back(i);
    T[v].push_back(i);
  }
  if(n == 2){
    cout << 0 << "\n";
    return 0;
  }
  else if(n == 3){
    cout << 0 << "\n" << 1 << "\n";
    return 0;
  }
  for(int i = 1; i <= n; i ++ ){
    if(T[i].size() >= 3){
      int c;
      for(int j = 0 ; j < n-1; j ++ ){
        f[j] = -1;
      }
      c = 0;
      for(int j = 0 ; j < 3; j ++ ){
        f[T[i][j]] = c;
        c ++ ;
      }
      for(int j = 0 ; j < n-1; j ++ ){
        if(f[j] == -1){
          f[j] = c;
          c ++ ;
        }
      }
      for(int i = 0 ; i < n-1; i ++ )
        cout << f[i] << "\n";
      return 0;
    }
  }
  for(int i = 0 ; i < n-1; i ++ )
    cout << i << "\n";
  return 0;
}