#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = 700;

struct fenwick{
  int bit[N];
  void upd(int i, int val){
    for(; i < N; i += (i & -i)){
      bit[i] += val;
    }
  }
  int ask(int i){
    int result = 0;
    for(; i > 0; i &= i - 1){
      result += bit[i];
    }
    return result;
  }
};

int n, q, sz;
int a[N];
int fr[N];
int to[N];
fenwick st;
fenwick fwt[N / M + 5];

int getidx(int i){
  return (i - 1) / M;
}

int query(int i){
  int val = a[i], where = getidx(i);
  int answer = 0;
  for(int k = i - 1; k >= fr[where]; --k){
    answer += (a[k] > val);
  }
  for(int k = i + 1; k <= to[where]; ++k){
    answer += (a[k] < val);
  }
  for(int other = 0; other < where; ++other){
    answer += (fr[other] - to[other] + 1) - fwt[other].ask(val);
  }
  for(int other = where + 1; other <= sz; ++other){
    answer += fwt[other].ask(val);
  }
  return answer;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++i){
    a[i] = i;
    int where = getidx(i);
    fwt[where].upd(a[i], 1);
    if(fr[where] == 0){
      fr[where] = i;
    }
    to[where] = i;
    sz = where;
  }
  long long answer = 0;
  for(int i = 1; i <= q; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    if(u == v){
      printf("%lld\n", answer);
      continue;
    }
    if(u > v){
      swap(u, v);
    }
    long long sub = query(u) + query(v) - (a[u] > a[v]);
    answer -= sub;
    fwt[getidx(u)].upd(a[u], -1);
    fwt[getidx(v)].upd(a[v], -1);
    swap(a[u], a[v]);
    fwt[getidx(u)].upd(a[u], 1);
    fwt[getidx(v)].upd(a[v], 1);
    answer += query(u) + query(v) - (a[u] > a[v]);
    printf("%lld\n", answer);
  }
  return 0;
}