#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
    int n, m, x;
    cin >> n >> x >> m;
    int l = x, r = x;
    int li, ri;
    for(int i = 0 ; i < m ; i ++ ){
      cin >> li >> ri;
      if(max(l,li) <= min(r,ri)){
        l=min(l,li);
        r=max(r,ri);
      }
    }
    cout << r - l + 1 << "\n";
  }
  return 0;
}