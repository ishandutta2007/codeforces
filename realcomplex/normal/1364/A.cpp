#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n, x;
  cin >> n >> x;
  vector<int> cur(n);
  int sum = 0;
  for(int i = 0 ; i < n; i ++ ){
    cin >> cur[i];
    cur[i] %= x;
    sum += cur[i];
    sum %= x;
  }
  int pf = 0, sf = 0;
  if(sum == 0){
    for(int i = 0 ; i < n; i ++ ){
      if(cur[i] == 0) pf ++ ;
      else break;
    }
    for(int i = n - 1; i >= 0 ; i -- ){
      if(cur[i] == 0) sf ++ ;
      else break;
    }
    if(pf == n)
      cout << "-1\n";
    else
      cout << n - min(pf,sf) -1 << "\n";
  }
  else{
    cout << n << "\n";
  }
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ )
    solve();
  return 0;
}