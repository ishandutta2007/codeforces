#include <set>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for (int query = 0; query < t; ++query){
    long long x;
    cin >> x;
    long long m = x, k = 1, b = 0;
    vector<long long> ans;
    while (k <= x){
      ans.push_back(m);
      long long tmp = b / m;
      k += tmp + 1;
      m = x / k;
      b = x % k;
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (long long y : ans)
      cout << y << ' ';
    cout << '\n';
  }
  return 0;
}