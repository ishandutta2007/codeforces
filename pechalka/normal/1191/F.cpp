#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>
#include <deque>
#include <set>

using namespace std;

vector<int> S;

int sum(int i){
  int ans = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    ans += S[i];
  return ans;
}

void add(int i, int x){
  for (; i < S.size(); i = i | (i + 1))
    S[i] += x;
}

int sum(int l, int r){
  return sum(r - 1) - sum(l - 1);
}

int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> points(n);
  vector<int> allx;
  for (int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;
    allx.push_back(x);
    points[i] = {-y, x};
  }
  sort(points.begin(), points.end());
  sort(allx.begin(), allx.end());
  S.resize(n);
  vector<bool> is(n, false);
  long long ans = 0;
  int first = 0;
  while (first < n){
    int last = first + 1;
    while (last < n && points[last].first == points[first].first)
      ++last;
    vector<int> cnt(last - first + 1);
    cnt[0] = sum(0, lower_bound(allx.begin(), allx.end(), points[first].second) - allx.begin()) + 1;
    cnt.back() = sum(upper_bound(allx.begin(), allx.end(), points[last - 1].second) - allx.begin(), n) + 1;
    for (int i = first + 1; i < last; ++i)
      cnt[i - first] = sum(upper_bound(allx.begin(), allx.end(), points[i - 1].second) - allx.begin(),
          lower_bound(allx.begin(), allx.end(), points[i].second) - allx.begin()) + 1;
    long long sum = 0;
    long long sqrSum = 0;
    for (int x : cnt){
      sum += (long long) x;
      sqrSum += ((long long) x) * ((long long) x);
    }
    ans += (sum * sum - sqrSum) / 2;
    for (int i = first; i < last; ++i){
      int ind = lower_bound(allx.begin(), allx.end(), points[i].second) - allx.begin();
      if (!is[ind]) {
        add(ind, 1);
        is[ind] = true;
      }
    }
    first = last;
  }
  cout << ans;
  return 0;
}