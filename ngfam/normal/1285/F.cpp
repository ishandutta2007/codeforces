#include<bits/stdc++.h>
#define left pinkgermany
#define right germanypink

using namespace std;

const int MAXN = 100010;

int n;
int a[MAXN];

int sum[MAXN];
int mid[MAXN];
int left[MAXN];
int right[MAXN];
int risan[MAXN];

long long ans;

int log2_[MAXN];
int query_size[MAXN];
int mask_count[MAXN];
vector < int > prime_factor[MAXN];
vector < pair < int, int > > queries[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  for(int i = 2; i < MAXN; ++i) {
    if(prime_factor[i].size()) continue;
    for(int j = i; j < MAXN; j += i) prime_factor[j].push_back(i);
  }

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    long long x; cin >> x;
    a[x] = 1;
    ans = max(ans, x);
  }

  for(int i = 2; i < MAXN; ++i) {
    log2_[i] = log2_[i >> 1] + 1;
  }

  for(int g = 1; g < MAXN; g++) {
    vector < int > b;
    b.reserve(MAXN / g + 1);

    for(int x = g; x < MAXN; x += g) {
      if(a[x]) b.push_back(x / g);
    }

    if(b.size() == 0) continue;

    for(int i = 1; i < b.size(); ++i) {
      risan[i] = -1;
      left[i] = 0;
      right[i] = i - 1;
      if(b[i - 1] + 1 == b[i]) {
        risan[i] = i - 1;
        left[i] = i;
      }
    }

    int max_log = log2_[b.size()] + 1;

    for(int log_ = 0; log_ < max_log; ++log_){
      for(int i = 1; i < b.size(); ++i) {
        if(left[i] > right[i]) continue;
        mid[i] = (left[i] + right[i]) >> 1;
        ++query_size[i - 1];
        if(mid[i] > 0) ++query_size[mid[i] - 1];
      }

      for(int i = 0; i < b.size(); ++i) queries[i].reserve(query_size[i] + 1);
      for(int i = 1; i < b.size(); ++i) {
        if(left[i] > right[i]) continue;
        queries[i - 1].push_back({i, b[i]});
        if(mid[i] > 0) queries[mid[i] - 1].push_back({-i, b[i]});
      }

      /***
        Count from mid[i] to i - 1
          how many numbers which is coprime to i
        can be done with ex-inclusion, which is i - mid[i] - number of numbers is not coprime
      ***/

      for(int i = 0; i < b.size(); ++i) {
        for(int mask = 0; mask < (1 << prime_factor[b[i]].size()); ++mask){
          int prod = 1;
          for(int j = 0; j < prime_factor[b[i]].size(); ++j) {
            if(mask & (1 << j)) prod *= prime_factor[b[i]][j];
          }
          ++mask_count[prod];
        }
        for(auto &q : queries[i]) {
          int id = abs(q.first), sign = id / q.first, val = q.second;
          for(int mask = 0; mask < (1 << prime_factor[val].size()); ++mask) {
            int prod = 1;
            for(int j = 0; j < prime_factor[val].size(); ++j) {
              if(mask & (1 << j)) prod *= prime_factor[val][j];
            }
            int sign2 = __builtin_popcount(mask) % 2 ? -1 : 1;
            sum[id] += sign * sign2 * mask_count[prod];
          }
        }
      }

      for(int i = 1; i < b.size(); ++i) {
        if(left[i] > right[i]) continue;
        if(sum[i]) {
          risan[i] = mid[i];
          left[i] = mid[i] + 1;
        }
        else right[i] = mid[i] - 1;
      }

      for(int i = 0; i < b.size(); ++i) {
        queries[i].clear();
        query_size[i] = 0;
        sum[i] = 0;
        for(int mask = 0; mask < (1 << prime_factor[b[i]].size()); ++mask){
          int prod = 1;
          for(int j = 0; j < prime_factor[b[i]].size(); ++j) {
            if(mask & (1 << j)) prod *= prime_factor[b[i]][j];
          }
          mask_count[prod] = 0;
        }
      }
    }

    for(int i = 1; i < b.size(); ++i) {
      if(risan[i] >= 0) ans = max(ans, 1LL * b[i] * b[risan[i]] * g);
    }
  }

  cout << ans << "\n";

  return 0;
}