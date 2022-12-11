#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

bool has[105];

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  int a[n];
  for(int i = 0;i < n;i ++ ){
    cin >> a[i];
  }
  int ans = 0;
  for(int i = 0;i < n; i ++ ){
    int cheap = 1249124;
    int odd = 0;
    int even =0;
    int pos = -1;
    for(int j = 0;j < n;j ++ ){
      if(a[j] % 2 == 1)
        odd ++ ;
      else
        even ++ ;
      if(odd == even){
        if(j + 1 != n){
          if(has[j + 1])
            continue;
          if(ab(a[j + 1] - a[j]) < cheap){
            cheap = ab(a[j + 1] - a[j]);
            pos = j + 1;
          }
        }
      }
    }
    if(pos != -1){
      if(cheap <= k){
        ans ++ ;
        has[pos] = true;
        k -= cheap;
      }
    }
  }
  cout << ans;
  return 0;
}