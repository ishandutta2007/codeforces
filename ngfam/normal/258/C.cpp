#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int mod = 1e9 + 7;

int n;
int a[N];
int cnt[N];
int maxval;

int powmod(int x, int y){
  if(y == 0){
    return 1;
  }
  if(y == 1){
    return x;
  }
  int calc = powmod(x, y >> 1);
  calc = (1LL * calc * calc) % mod;
  if(y & 1){
    calc = (1LL * calc * x) % mod;
  }
  return calc;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    maxval = max(maxval, a[i]);
    ++cnt[a[i]];
  }
  for(int i = 1; i < N; ++i){
    cnt[i] += cnt[i - 1];
  }
  int answer = 0;
  for(int val = 1; val <= maxval; ++val){
    vector < int > lst;
    for(int dv = 1; dv * dv <= val; ++dv){
      if(val % dv != 0){
        continue;
      }
      lst.push_back(dv);
      if(dv * dv != val){
        lst.push_back(val / dv);
      }
    }
    sort(lst.begin(), lst.end());
   /* cout << val << " : ";
    for(int x : lst){
      cout << x << " ";
    }
    cout << endl;*/
    int product = 1;
    for(int i = 0; i < lst.size() - 1; ++i){
      //int len = lst[i + 1] - lst[i];
      //cerr << len << " ";
      product = (1LL * product * powmod(i + 1, cnt[lst[i + 1] - 1] - cnt[lst[i] - 1])) % mod;
    }
  //  cerr << endl;
    int nw = cnt[N - 1] - cnt[lst.back() - 1];
    int rev = powmod(lst.size() - 1, nw);
    int tot = powmod(lst.size(), nw);
  //  cerr << rev << " " << tot << endl;
    tot = (tot - rev + mod) % mod;
    product = (1LL * product * tot) % mod;
  //  cerr << product << endl;
//    product = (1LL * product * powmod(lst.size(), nw - 1));
    answer = (answer + product) % mod;
  }
  cout << answer;
  return 0;
}