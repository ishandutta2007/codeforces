#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ; t < tc; t ++ ){
    int n;
    cin >> n;
    int dec = 0, add = 0;
    int a[n], b[n];
    for(int i = 0 ; i < n; i ++ )
      cin >> a[i];
    for(int i = 0 ; i < n;  i ++ )
      cin >> b[i];
    bool can = true;
    for(int i = 0 ; i < n; i ++ ){
      if(a[i] < b[i]){
        if(!add){
          can = false;
        }
      }
      else if(a[i] > b[i]){
        if(!dec){
          can = false;
        }
      }
      if(a[i] == 1) add = 1;
      else if(a[i] == -1) dec = 1;
    }
    if(can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}