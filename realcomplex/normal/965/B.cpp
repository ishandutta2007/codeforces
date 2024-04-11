#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

const int N = 101;
int cnt[N][N];
char conf[N][N];

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= n;j ++ ){
      cin >> conf[i][j];
    }
  }
  // ---------->
  bool ok;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= n-k+1;j ++ ){
      ok = true;
      for(int x = 0;x < k; x ++ ){
        if(conf[i][j + x] == '#'){
          ok = false;
        }
      }
      if(ok){
        for(int x = 0;x < k; x ++ ){
          cnt[i][j + x] ++ ;
        }
      }
    }
  }
  // | | | | | | | | | | | | | |
  // v v v v v v v v v v v v v v
  for(int i = 1;i <= n - k + 1;i ++ ){
    for(int j = 1;j <= n;j ++ ){
      ok = true;
      for(int x = 0;x < k; x ++ ){
        if(conf[i + x][j] =='#'){
          ok = false;
        }
      }
      if(ok){
        for(int x = 0;x < k; x ++ ){
          cnt[i + x][j] ++ ;
        }
      }
    }
  }
  int t1 = 1, t2 = 1;
  int current = 0;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= n;j ++ ){
      if(cnt[i][j] > current){
        current = cnt[i][j];
        t1 = i;
        t2 = j;
      }
    }
  }
  cout << t1 << " " << t2 << "\n";
  return 0;
}