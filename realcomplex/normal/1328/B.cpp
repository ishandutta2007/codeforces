#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
char f[N];

int main(){
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ ){
      f[i] = 'a';
    }
    for(int i = n-1; i >= 1; i -- ){
      if(k > n - i){
        k -= n - i;
      }
      else{
        f[i] = 'b';
        f[n - k + 1] = 'b';
        break;
      }
    }
    for(int i = 1; i <= n; i ++ ){
      cout << f[i];
    }
    cout << "\n";
  }
  return 0;
}