#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n;
int permu[N];
int nxt[N];
string t, p, a;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "W", stdout);
  #endif // pts
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t >> p;
  n = t.size();
  for(int i = 1; i <= n; ++i){
    cin >> permu[i];
    --permu[i];
  }
  int low = 1, high = n, answer = 0;
  while(low <= high){
    int mid = (low + high) >> 1;
    a = t;
    for(int i = 1; i <= mid; ++i){
      a[permu[i]] = '#';
    }
    memset(nxt, 0, sizeof nxt);
    nxt[0] = (a[0] == p[0]);
    for(int i = 1; i < n; ++i){
      if(nxt[i - 1] == p.size()){
        nxt[i] = nxt[i - 1];
        continue;
      }
      nxt[i] = nxt[i - 1] + (a[i] == p[nxt[i - 1]]);
    }
    if(nxt[n - 1] == p.size()){
      answer = mid;
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  cout << answer;
  return 0;
}