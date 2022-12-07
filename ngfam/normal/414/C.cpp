#include <bits/stdc++.h>
#define mid ((l + r) >> 1)

using namespace std;

const int N = 1 << 21;

int n, m;
int a[N];
long long inv[N];
long long rev[N];
vector < int > it[N * 2];

long long calc(vector < int > &x, vector < int > &y){
  int pter = 0;
  long long answer = 0;
  for(int i = 0; i < x.size(); ++i){
    while(pter < y.size() && y[pter] < x[i]){
      ++pter;
    }
    answer += pter;
  }
  return answer;
}

void write(vector < int > &x){
  for(int v : x){
    cerr << v << " ";
  }
  cerr << endl;
}

void solve(int u, int l, int r){
  if(l == r){
    it[u].push_back(a[r]);
    return;
  }
  solve(u << 1, l, mid);
  solve(u << 1 | 1, mid + 1, r);
  int h = log2(r - l + 1);
  inv[h] += calc(it[u << 1], it[u << 1 | 1]);
  rev[h] += calc(it[u << 1 | 1], it[u << 1]);
  it[u].resize(r - l + 1);
  merge(it[u << 1].begin(), it[u << 1].end(), it[u << 1 | 1].begin(), it[u << 1 | 1].end(), it[u].begin());
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
  #endif // ONLINE_JUDGE
  scanf("%d", &n);
  for(int i = 1; i <= (1 << n); ++i){
    scanf("%d", a + i);
  }
  scanf("%d", &m);
  solve(1, 1, 1 << n);
  while(m--){
    int x;
    scanf("%d", &x);
    for(int i = 0; i <= x; ++i){
      swap(rev[i], inv[i]);
    }
    long long answer = 0;
    for(int i = 0; i <= n; ++i){
      answer += inv[i];
    }
    printf("%lld\n", answer);
  }
  return 0;
}