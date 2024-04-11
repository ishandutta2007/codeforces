#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int cntodd = 0, cnteven = 0;
  int n; cin >> n;
  vector < int > a(n);

  for(int &x : a) {
    cin >> x;
    if(x % 2) ++cntodd;
    else ++cnteven;
  }

  if(cntodd && cnteven) sort(a.begin(), a.end());
  for(int x : a) cout << x << " ";
  
  return 0;
}