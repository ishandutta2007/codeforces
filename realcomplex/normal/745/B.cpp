#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  int mx = 0, my = 0, qx = n + 1,qy = m + 1;
  char v;
  int cnt = 0;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= m ;j ++){
      cin >> v;
      if(v == 'X'){
        cnt ++ ;
        mx = max(mx, i);
        qx = min(qx, i);
        my = max(my, j);
        qy = min(qy, j);
      }
    }
  }
  if((mx - qx + 1) * (my - qy + 1) == cnt)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}