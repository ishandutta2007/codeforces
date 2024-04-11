#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  ll k;
  ll ans = 0;
  for(int i = 1;i<=n;i++){
    cin >> k;
    ans+=(i*(k-1));
    ans++;
  }
  cout << ans << "\n";
  return 0;
}