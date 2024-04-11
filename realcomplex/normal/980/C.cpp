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
#define ones(a) __builtin_popcount(a)

int key[256];

int main(){
  fastIO;
  for(int i = 0;i < 256;i ++ )
    key[i] = -1; 
  int n,k;
  cin >> n >> k;
  int p;
  for(int i = 0;i < n;i ++ ){
    cin >> p;
    if(key[p] == -1){
      for(int j = max(0, p - k + 1); j <= p;j ++ ){
        if(key[j] == -1 or key[j] == j){
          for(int x = j;x <= p; x ++ ){
            key[x] = j;
          }
          break;
        }
      }
    }
    cout << key[p] << " ";
  }
  return 0;
}