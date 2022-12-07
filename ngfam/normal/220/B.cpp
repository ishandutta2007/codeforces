#include <bits/stdc++.h>

using namespace std;

const int N = 123456, Base = 320;

struct query{
  int fr;
  int to;
  int idx;
}ask[N];

int n, m, curr;
int arr[N];
int value[N];
int f[N];
int answer[N];
vector < int > small;
vector < query > block[Base];

void ins(int x, int k){
  if(f[x] == value[x]){
    --curr;
  }
  f[x] += k;
  if(f[x] == value[x]){
    ++curr;
  }
}

bool cmp(query u, query v){
  return u.fr < v.fr;
}

bool cmp2(query u, query v){
  return u.to < v.to;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", arr + i);
    small.push_back(arr[i]);
  }
  sort(small.begin(), small.end());
  unique(small.begin(), small.end());
  int mm = small.size();
  for(int i = 0; i < small.size() - 1; ++i){
    if(small[i] >= small[i + 1]){
      mm = i + 1;
      break;
    }
  }
  small.resize(mm);
  for(int i = 1; i <= n; ++i){
    int fin = lower_bound(small.begin(), small.end(), arr[i]) - small.begin();
    ++fin;
    value[fin] = arr[i];
    arr[i] = fin;
  }
  for(int i = 1; i <= m; ++i){
    int fr, to;
    scanf("%d%d", &fr, &to);
    ask[i] = {fr, to, i};
  }
  sort(ask + 1, ask + m + 1, cmp);
  for(int i = 1; i <= m; ++i){
    int fin = (ask[i].fr - 1) / Base + 1;
    block[fin].push_back(ask[i]);
  }
  for(int tt = 1; tt < Base; ++tt){
    sort(block[tt].begin(), block[tt].end(), cmp2);
  }
  for(int tt = 1; tt < Base; ++tt){
    if(block[tt].size() == 0){
      continue;
    }
    memset(f, 0, sizeof f);
    curr = 0;
    for(int i = block[tt][0].fr; i <= block[tt][0].to; ++i){
      ins(arr[i], 1);
    }
    answer[block[tt][0].idx] = curr;
    for(int idx = 1; idx < block[tt].size(); ++idx){
      int fpre = block[tt][idx - 1].fr, tpre = block[tt][idx - 1].to;
      int fcur = block[tt][idx].fr, tcur = block[tt][idx].to;
      if(fpre < fcur){
        for(int i = fpre; i < fcur; ++i){
          ins(arr[i], -1);
        }
      }
      else{
        for(int i = fcur; i < fpre; ++i){
          ins(arr[i], 1);
        }
      }
      if(tpre < tcur){
        for(int i = tpre + 1; i <= tcur; ++i){
          ins(arr[i], 1);
        }
      }
      else{
        for(int i = tcur + 1; i <= tpre; ++i){
          ins(arr[i], -1);
        }
      }
      answer[block[tt][idx].idx] = curr;
    }
  }
  for(int i = 1; i <= m; ++i){
    printf("%d\n", answer[i]);
  }
  return 0;
}