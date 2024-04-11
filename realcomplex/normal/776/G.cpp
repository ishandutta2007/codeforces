#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int LEN = 20;

ll dp[LEN][2][2];

int idx(char x){
  if(x >= '0' && x <= '9')
    return x - '0';
  else
    return 10 + (x - 'a');
}

vector<int> transf(string f){
  vector<int> sol;
  for(char x : f) sol.push_back(idx(x));
  return sol;
}

ll calc(string f){
  vector<int> ss = transf(f);
  int n = ss.size();
  ll res = 0;
  int id;
  for(int shit = 1; shit <= 15; shit ++ ){
    id = 4 * n - 1 - shit; 
    if(id < 0) continue;
    for(int i = 0 ; i <= n; i ++ ){
      for(int x = 0 ; x < 2; x ++ ){
        for(int y = 0; y < 2; y ++ ){
          dp[i][x][y]=0;
        }
      }
    }
    dp[0][0][0]=1;
    int cd1,cd2;
    for(int i = 0 ; i < n; i ++ ){
      for(int hh = 0 ; hh < 2; hh ++ ){
        for(int sh = 0 ; sh < 2; sh ++ ){
          for(int nx = (i==0) ; nx <= shit; nx ++ ){
            if(hh == 0 && nx > ss[i]) continue;
            if(i * 4 <= id && i * 4 + 3 >= id){
              if(!(nx & (1<<(i*4+3-id)))){
                continue;
              }
            }
            cd1 = hh | (nx < ss[i]);
            cd2 = sh | (nx == shit);
            dp[i+1][cd1][cd2] += dp[i][hh][sh];
          }
        }
      }
    }
    res += dp[n][0][1] + dp[n][1][1];
  }
  return res;
}

bool good(string t){
  ll x = 1ll;
  int cur;
  int mx = 0;
  ll sum = 0;
  for(int i = t.size() - 1; i >= 0 ; i -- ){
    cur = idx(t[i]);
    mx = max(mx, cur);
    sum += cur * x;
    x *= 16ll;
  }
  if(sum & (1 << mx)) return true;
  return false;
}

ll sol[LEN];

ll f(string t){
  int n = t.size();
  ll ans = 0;
  for(int i = 1; i < n ; i ++ )
    ans += sol[i];
  ans += calc(t);
  return ans;
}

void solve(){
  string a, b;
  cin >> a >> b;
  cout << f(b) - f(a) + good(a) << "\n";
}

int main(){
  fastIO;
  string cur;
  for(int i = 1; i < LEN; i ++ ){
    cur.push_back('f');
    sol[i] = calc(cur);
  }
  int q;
  cin >> q;
  for(int i = 0 ; i < q;  i ++ ){
    solve();
  }
  return 0;
}