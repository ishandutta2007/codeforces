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
  vector<int> t;
  char f;
  for(int i = 0 ; i < n; i ++ ){
    cin >> f;
    t.push_back(f - '0');
  }
  int a[n], b[n];
  for(int i = 0 ; i < n ; i ++ ){
    cin >> a[i] >> b[i];
  }
  int res = 0;
  int cur;
  for(int i = 0 ; i < 25000; i ++ ){
    cur = 0;
    for(int j = 0 ; j < n; j ++ ){
      if(i >= b[j] && (i - b[j]) % a[j] == 0)
        t[j] = 1 - t[j];
    }
    for(int j = 0 ; j < n ; j ++ )
      cur += t[j];
    res = max(res, cur);
  }
  cout << res;
  return 0;
}