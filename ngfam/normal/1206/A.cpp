#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m, maxa = 0, maxb = 0;
  cin >> n;

  while(n--) {
    int x; cin >> x;
    maxa = max(maxa, x);
  }

  cin >> m;
  while(m--) {
    int x; cin >> x;
    maxb = max(maxb, x);
  }

  cout << maxa << " " << maxb << endl;

  return 0;
}