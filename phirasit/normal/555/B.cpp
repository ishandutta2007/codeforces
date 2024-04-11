#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long, int> pii;

const int N = 200010;

vector<int> idx;
vector<int> ans;
set<pii> S;
long long mx[N];
long long x[N], y[N];
int n, m;

long long fabs(long long x) {
  return x < 0ll ? -x : x;
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0;i < n;i++) {
    scanf("%I64d%I64d", &x[i], &y[i]);
  }
  for(int i = 0;i < m;i++) {
    long long val;
    scanf("%I64d", &val);
    S.insert({val, i+1});
  }
  idx.resize(n-1);
  ans.resize(n-1);
  for(int i = 0;i < n-1;i++) {
    mx[i] = max(fabs(y[i+1] - x[i]), fabs(y[i+1] - y[i]));
    mx[i] = max(mx[i], max(fabs(x[i+1] - x[i]), fabs(x[i+1] - y[i])));
    idx[i] = i;
  }
  sort(idx.begin(), idx.end(), [&](int id1, int id2) {
    return mx[id1] < mx[id2];
  });
  for(int i : idx) { 
    long long df = fabs(min(y[i+1], y[i]) - max(x[i+1], x[i]));
    auto it = S.lower_bound({df, 0});
    if(it == S.end()) {
      printf("No\n");
      return 0;
    }
    if(it->first > mx[i]) {
      printf("No\n");
      return 0;
    }
    ans[i] = it->second;
    S.erase(it);
  }
  printf("Yes\n");
  for(int i = 0;i < ans.size();i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}