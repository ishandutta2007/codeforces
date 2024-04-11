#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

bool is(int x){
  int y = sqrt(x);
  return x == y * y;
}

int conv(string s){
  int c = 1;
  int rz = 0;
  for(int i = s.size() - 1;i >= 0; i -- ){
    rz += c * (s[i] - 48);
    c *= 10;
  }
  return rz;
}

int main(){
  fastIO;
  string k;
  cin >> k;
  int n = k.size();
  int ans = 999;
  int bit;
  for(int i = 0;i < (1 << n); i ++ ){
    string res;
    bit = 0;
    for(int j = 0;j < n; j ++ ){
      if(i & (1 << j)){
        res += k[j];
      }
      else{
        bit ++ ;
      }
    }
    if(res.empty())
      continue;
    if(res[0] == '0')
      continue;
    if(is(conv(res))){
      ans = min(ans , bit);
    }
  }
  cout << (ans == 999 ? -1 : ans);
  return 0;
}