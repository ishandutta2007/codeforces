#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int inf = -1u/2;
const int N = 200010;
const int T = 3;

multiset<int> S;
int pw[T], n;

void rem(int x) {
  auto it = S.upper_bound(x);
  if(it != S.begin()) {
    S.erase(prev(it));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0;i < T;i++) cin >> pw[i];
  sort(pw, pw+T);
  for(int i = 0;i < n;i++) {
    int val;
    cin >> val;
    S.insert(val);
  }
  int ans = 0;
  while(!S.empty()) {
    ans++;
    int val = *prev(S.end());
    S.erase(prev(S.end()));
    if(val > pw[0] + pw[1] + pw[2]) {
      ans = -1;
      break;
    }
    if(val <= pw[0]) {
      rem(pw[1]);
      rem(pw[2]);
      continue;
    }else if(val <= pw[1]) {
      rem(pw[0]);
      rem(pw[2]);
      continue;
    }else if(val <= pw[2]) {
      bool err = false;
      auto it = S.upper_bound(pw[1]);
      if(it == S.begin()) err = true;
      if(!err) {
        int val1 = *prev(it);
        S.erase(prev(it));
        auto it2 = S.upper_bound(pw[0]);
        if(it2 == S.begin()) err = true;
        if(err) S.insert(val1);
        else S.erase(prev(it2));
      }
      if(err) {
        rem(pw[0] + pw[1]);
      }
      continue;
    }
    int lf = -1;
    if(val <= pw[0] + pw[1]) lf = max(lf, pw[2]);
    if(val <= pw[1] + pw[2]) lf = max(lf, pw[0]);
    if(val <= pw[0] + pw[2]) lf = max(lf, pw[1]);
    rem(lf);
  }
  cout << ans << endl;
  return 0;
}