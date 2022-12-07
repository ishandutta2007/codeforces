#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  if(n % 2 == 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;

  vector < int > ans(n * 2);
  for(int i = 0; i < n; ++i) {
    ans[i] = i * 2 + 1;
    ans[i + n] = i * 2 + 2;
    if(i % 2 == 0) swap(ans[i], ans[i + n]);
  }

  for(int x : ans) cout << x << " ";

  return 0;
}