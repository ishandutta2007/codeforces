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
  int n;
  cin >> n;
  int m[n];
  for(int i = 0 ; i < n ; i ++ ){
    cin >> m[i];
  }
  ll tot = 0;
  int low;
  int idx = -1;
  ll cur;
  for(int i = 0 ; i < n ; i ++ ){
    low = m[i];
    cur = m[i];
    for(int j = i - 1; j >= 0 ; j -- ){
      low = min(low, m[j]);
      cur += low;
    }
    low = m[i];
    for(int j = i + 1; j < n; j ++ ){
      low = min(low, m[j]);
      cur += low;
    }
    if(cur > tot){
      tot = cur;
      idx = i;
    }
  }
  for(int i = idx - 1; i >= 0 ; i -- ){
    m[i] = min(m[i], m[i + 1]);
  }
  for(int i = idx + 1; i < n; i ++ ){
    m[i] = min(m[i], m[i - 1]);
  }
  for(int i = 0 ; i < n ; i ++ )
    cout << m[i] << " ";
  return 0;
}