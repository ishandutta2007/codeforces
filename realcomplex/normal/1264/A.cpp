#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0 ; i < n ; i ++ )
    cin >> p[i];
  int m[3] = {0,0,0};
  int cur = 1;
  int f = 0;
  for(int i = 1; i < n ; i ++ ){
    if(p[i] == p[i - 1]){
      cur ++ ;
    }
    else{
      if(2 * (m[0] + m[1] + m[2] + cur) > n) break;
      m[f] += cur;
      if(f == 0 || f != 1 || m[f] > m[f - 1])
        f = min(f + 1, 2);
      cur = 1;
    }
  }
  if(2 * (m[0] + m[1] + m[2] + cur) <= n)
    m[2] += cur;
  if(2 * (m[0] + m[1] + m[2]) > n || m[0] >= m[1] || m[0] >= m[2]){
    cout << "0 0 0" << "\n";
    return;
  }
  cout << m[0] << " " << m[1] << " " << m[2] << "\n";
}

int main(){
  fastIO;
  int testc;
  cin >> testc;
  while(testc--){
    solve();
  }
  return 0;
}