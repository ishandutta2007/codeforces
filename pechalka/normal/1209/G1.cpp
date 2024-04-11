#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

const int MAXVAL = 200001;

int last[MAXVAL];
int cnt[MAXVAL];

int main(){
  for (int i = 1; i < MAXVAL; ++i)
    last[i] = -1;

  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  for (int i = 0; i < n; ++i){
    last[A[i]] = i;
    ++cnt[A[i]];
  }
  int now = 0;
  int til = 0;
  vector<int> edgesEnd;
  while (now < n){
    til = max(til, last[A[now]]);
    if (til == now)
      edgesEnd.emplace_back(now);
    ++now;
  }
  int ans = 0;
  int first = 0;
  for (int edge = 0; edge < edgesEnd.size(); ++edge){
    int second = edgesEnd[edge];
    int mx = 0;
    for (int i = first; i <= second; ++i)
      mx = max(mx, cnt[A[i]]);
    ans += second - first + 1 - mx;
    first = edgesEnd[edge] + 1;
  }
  cout << ans;
  return 0;
}