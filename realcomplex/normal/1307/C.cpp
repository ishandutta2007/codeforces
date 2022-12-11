#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int AL = 26;
ll cnt[AL][AL];
ll cc[AL];

int main(){
  fastIO;
  string t;
  cin >> t;
  ll res = 0;
  for(auto x : t){
    for(int j = 0 ; j < AL; j ++ ){
      cnt[j][x - 'a'] += cc[j];
    }
    cc[x - 'a'] ++ ;
  }
  for(int i = 0 ; i < AL; i ++ ){
    for(int j = 0 ; j < AL; j ++ ){
      res = max(res, cnt[i][j]);
    }
    res = max(res, cc[i]);
  }
  cout << res << "\n";
  return 0;
}