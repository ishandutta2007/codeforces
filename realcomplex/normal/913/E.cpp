#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = (1 << 8);
string dp[M];

int conv(string t){
  int b = 1;
  int sum = 0;
  for(int i = 0 ; i < t.size(); i ++ ){
    sum += (t[i] - '0') * b;
    b *= 2;
  }
  return sum;
}


void upd(int id, string b){ 
  if(dp[id] == "#") dp[id]=b;
  else{
    if(b.size() < dp[id].size()) {
      dp[id]=b;
    }
    else if(b.size() == dp[id].size()){
      dp[id]=min(dp[id],b);
    }
  }
}

bool has(string t, char bad){
  int bal = 0;
  for(char x : t){
    if(x == '(') bal ++ ;
    else if(x == ')') bal -- ;
    if(x == bad && bal == 0) return true;
  }
  return false;
}

string combine(string p, string q, char betw){
  if(betw == '|') return p + betw + q;
  if(has(p,'|'))
    p = "(" + p + ")";
  if(has(q,'|'))
    q = "(" + q + ")";
  return p + betw + q;
}


string ntt(string q){ 
  if(has(q,'|') || has(q,'&')){
    q = '(' + q + ')';
  }
  q = '!' + q;
  return q;
}

int main(){
  fastIO;
  for(int i = 0 ; i < M ; i ++ )
    dp[i]="#";
  upd(conv("00000000"), "!x&x");
  upd(conv("00001111"), "x");
  upd(conv("00110011"), "y");
  upd(conv("01010101"), "z");

  string ai, bi;
  for(int it = 0; it < 9; it ++ ){
    if(it % 3 == 0){
      for(int i = 0 ; i < M ; i ++ ){
        if(dp[i] == "#") continue;
        for(int j = 0 ; j < M ; j ++ ){
          if(dp[j] == "#") continue;
          ai = dp[i];
          bi = dp[j];
          upd((i | j), combine(ai, bi, '|'));
          if(i > 0)
            upd(((M - i - 1) | j), combine(ntt(ai), bi, '|'));
        }
      }
    }
    else if(it % 3 == 1){
      for(int i = 0 ; i < M ; i ++ ){
        if(dp[i] == "#") continue;
        for(int j = 0 ; j < M ; j ++ ){
          if(dp[j] == "#") continue;
          ai = dp[i];
          bi = dp[j];
          upd((i & j), combine(ai, bi, '&'));
          upd((M - i - 1) & j, combine(ntt(ai), bi, '&'));
        }
      }
    }
    else{
      for(int i = 0; i < M ; i ++ ){
        if(dp[i] != "#"){
          upd(M - 1 - i, ntt(dp[i]));
        }
      }
    }
  }
  int q;
  cin >> q;
  string c;
  for(int i = 0 ; i < q; i ++ ){
    cin >> c;
    cout << dp[conv(c)] << "\n";
  }
  return 0; 
}