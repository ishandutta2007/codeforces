#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 20, Base = 320;

struct query{
  int l;
  int r;
  int idx;
};

int n, m, k;
int arr[N];
int f[N];
int fsub[N];
int sumxor[N];
long long answer = 0;
long long result[N];
query ask[N];
vector < query > block[Base];

bool cmp(query u, query v){
  return u.l < v.l;
}

bool cmp2(query u, query v){
  return u.r < v.r;
}

void ins(int u, int delta){
  if(delta == -1){
    --f[sumxor[u]];
    answer -= f[sumxor[u] ^ k];
  }
  else{
    answer += f[sumxor[u] ^ k];
    ++f[sumxor[u]];
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", arr + i);
  }
  for(int i = 1; i <= n; ++i){
    sumxor[i] = sumxor[i - 1] ^ arr[i];
  }
  for(int i = 1; i <= m; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    ask[i] = {l - 1, r, i};
  }
  sort(ask + 1, ask + m + 1, cmp);
  for(int i = 1; i <= m; ++i){
    int idx = (ask[i].l) / Base + 1;
    block[idx].push_back(ask[i]);
  }
  for(int i = 1; i < Base; ++i){
    sort(block[i].begin(), block[i].end(), cmp2);
  }
  for(int idx = 1; idx < Base; ++idx){
    if(block[idx].size() < 1){
      continue;
    }
    answer = 0;
    memset(f, 0, sizeof f);
    for(int i = block[idx][0].l; i <= block[idx][0].r; ++i){
      ins(i, 1);
    }
    result[block[idx][0].idx] = answer;
    for(int j = 1; j < block[idx].size(); ++j){
      if(block[idx][j].l < block[idx][j - 1].l){
        for(int pter = block[idx][j].l; pter < block[idx][j - 1].l; ++pter){
          ins(pter, 1);
        }
      }
      else{
        for(int pter = block[idx][j - 1].l; pter < block[idx][j].l; ++pter){
          ins(pter, -1);
        }
      }
      if(block[idx][j].r < block[idx][j - 1].r){
        for(int pter = block[idx][j].r + 1; pter <= block[idx][j - 1].r; ++pter){
          ins(pter, -1);
        }
      }
      else{
        for(int pter = block[idx][j - 1].r + 1; pter <= block[idx][j].r; ++pter){
          ins(pter, 1);
        }
      }
      result[block[idx][j].idx] = answer;
    }
  }
  for(int i = 1; i <= m; ++i){
    printf("%lld\n", result[i]);
  }
  return 0;
}