#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<string> seq = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
vector<int> masks;

int conv(string f){ 
  int res = 0;
  for(int i = 0 ; i < 7; i ++ ){
    if(f[i] == '1') res |= (1 << i);
  }
  return res;
}

const int N = 2005;
bool dp[N][N];
string f[N];
int dg[N];

int main(){
  fastIO;
  for(auto x : seq) masks.push_back(conv(x));
  int n, k;
  cin >> n >> k;
  for(int i = 0 ; i < n ;i  ++ ){
    cin >> f[i];
    dg[i] = conv(f[i]);
  }
  dp[n][0] = true;
  int add;
  for(int i = n; i > 0 ; i -- ){
    for(int j = 0 ; j <= k ; j ++ ){
      if(dp[i][j]){
        for(int t = 0; t < 10; t ++ ){
          if((dg[i - 1] & masks[t]) == dg[i - 1]){
            add = __builtin_popcount((masks[t] ^ dg[i - 1]));
            if(j + add <= k){
              dp[i - 1][j + add] = true;
            }
          }
        }
      }
    }
  }
  if(dp[0][k] == false){
    cout << "-1\n";
    return 0;
  }
  int cur = k;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 9 ; j >= 0 ; j -- ){
      if((dg[i] & masks[j]) != dg[i]) continue;
      if(dp[i + 1][cur - __builtin_popcount((masks[j]^dg[i]))]){
        cur -= __builtin_popcount((masks[j]^dg[i]));
        cout << j;
        break;
      }
    }
  }
  return 0;
}