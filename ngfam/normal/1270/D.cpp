#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  cout << "? ";
  for(int i = 1; i <= k; ++i) cout << i << " ";
  cout << endl;

  int pos, val; cin >> pos >> val;


  cout << "? ";
  for(int i = 1; i <= k + 1; ++i) if(i != pos) cout << i << " ";
  cout << endl;

  int pos2, val2; cin >> pos2 >> val2;

  int cnt[2] = {0, 0};
  int f = (val < val2);

  for(int i = 1; i <= k; ++i) {
    if(i == pos) continue;

    cout << "? ";
    for(int j = 1; j <= k + 1; ++j) if(j != i) cout << j << " ";
    cout << endl;

    int pos3, val3; cin >> pos3 >> val3;

    if(val3 == val) cnt[f]++;
    else cnt[1 - f]++;
  }

  cout << "! " << cnt[0] + 1 << endl;

  return 0;
}