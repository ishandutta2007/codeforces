#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 0 ; i < tc; i ++ ){
    int n;
    cin >> n;
    int col[n];
    int a[n];
    for(int j = 0 ; j < n; j ++ ){
      cin >> a[j];
      col[j] = -1;
    }
    int c = 0;
    bool use;
    for(int j = 2; j < 1001; j ++ ){
      use = false;
      for(int x = 0; x < n; x ++ ){
        if(a[x] % j == 0 && col[x] == -1){
          use = true;
          col[x] = c+1;
        }
      }
      if(use) c ++ ;
    }
    cout << c << "\n";
    for(int j = 0 ;j < n ; j ++ )
      cout << col[j] << " "; 
    cout << "\n";
  }
  return 0;
}