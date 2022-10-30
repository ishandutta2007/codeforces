#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

vector<long long> S;

long long sum(int i){
  long long ans = 0;
  for (; i > 0; i = (i & (i + 1)) - 1)
    ans += S[i];
  return ans;
}

void add(int i, long long x){
  for (; i < S.size(); i = i | (i + 1))
    S[i] += x;
}

int main(){
  int n;
  cin >> n;
  vector<long long> p(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];
  S.resize(n + 1);
  for (int i = 0; i < n; ++i)
    add(i + 1, i + 1);
  vector<int> res(n);
  for (int i = n - 1; i >= 0; --i){
    int left = 0, right = n;
    while (right - left > 1){
      int mid = (left + right) / 2;
      if (sum(mid) > p[i])
        right = mid;
      else
        left = mid;
    }
    res[i] = right;
    add(right, -right);
  }
  for (int x : res)
    cout << x << " ";
  return 0;
}