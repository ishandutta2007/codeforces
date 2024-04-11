#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int n, sz;
long long arr[N];
long long k;
long long sum;
long long pw[N];
long long pre[N];

map < long long, int > cnt;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
  #endif
  scanf("%d%lld", &n, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%lld", arr + i);
    sum += abs(arr[i]);
  }
  if(k == 0){
    cout << 0;
    return 0;
  }
  if(k == 1){
    pw[0] = 1;
  }
  else if(k == -1){
    sz = 1;
    pw[0] = 1;
    pw[1] = -1;
  }
  else{
  pw[0] = 1;
  for(int i = 1; i < N; ++i){
    if(pw[i - 1] * k > sum){
      break;
    }
    pw[++sz] = pw[i - 1] * k;
  }
  }
  long long answer = 0;
  ++cnt[0];
  for(int i = 1; i <= n; ++i){
    pre[i] = pre[i - 1] + arr[i];
    for(int j = 0; j <= sz; ++j){
      long long calc = pw[j];
      answer += cnt[pre[i] - calc];
    }
    ++cnt[pre[i]];
  }
  cout << answer;
  return 0;
}