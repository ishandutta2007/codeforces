#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;

int low[N];
int high[N];

void precalc(){
  int cur;
  int tk;
  for(int i = 1; i < N ; i ++ ){
    cur = i;
    high[i] = (i * (i - 1)) / 2;
    for(int j = 0 ; j < 15; j ++ ){
      tk = min((1 << j), cur);
      low[i] += tk * j;
      cur -= tk;
    }
  }
}

bool is_good(int n, int d){ 
  return (d >= low[n] && d <= high[n]);
}

vector<int> solve(int n ,int d){
  if(n == 1) return {};
  if(is_good(n - 1, d - n + 1)){
    vector<int> yy = solve(n - 1, d - n + 1);
    vector<int> ret;
    ret.push_back(1);
    for(auto x : yy)
      ret.push_back(x+1);
    return ret;
  }
  int r, f;
  for(int l = 1; l + 1 < n; l ++ ){
    for(int k = low[l]; k <= high[l]; k ++ ){
      r = n - l - 1;
      f = d - r - k - l;
      if(is_good(r, f)){
        vector<int> lf = solve(l, k);
        vector<int> rf = solve(r, f);
        vector<int> res;
        res.push_back(1);
        for(auto x : lf)
          res.push_back(x + 1);
        res.push_back(1);
        for(auto x : rf)
          res.push_back(x + 2 + lf.size());
        return res;
      }
    }
  }
  
}
int main(){
  fastIO;
  precalc();
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    int n, d;
    cin >> n >> d;
    if(!is_good(n,d)){
      cout << "NO\n";
    }
    else{
      cout << "YES\n";
      vector<int> res = solve(n, d);
      for(auto x : res)
        cout << x << " ";
      cout << "\n";
    }
  }
  return 0;
}