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
  ll k;
  cin >> k;
  string str = "codeforces";
  vector<int> cnt(10);
  for(int i = 0 ; i < 10 ; i ++ )
    cnt[i]=1;
  ll cur = 1;
  int id;
  ll mx;
  ll cc;
  while(cur < k){
    id = 0;
    mx = 0;
    for(int i = 0 ; i < 10 ; i ++ ){
      cc = (cur/cnt[i])*1ll*(cnt[i]+1);
      if(cc > mx){
        mx = cc;
        id = i;
      }
    }
    cnt[id] ++ ;
    cur = mx;
  }
  for(int i = 0 ;i < 10; i ++ ){
    for(int j = 0 ; j < cnt[i]; j ++ ){
      cout << str[i];
    }
  }
  return 0;
}