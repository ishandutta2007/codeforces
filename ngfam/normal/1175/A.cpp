#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int T; cin >> T;
  while(T--) {
    long long n, k; 
    cin >> n >> k;

    long long ans = 0;
    while(n != 0) {
      if(n % k == 0) {
        n /= k;
        ans += 1;
      }
      else {
        ans += n % k;
        n -= n % k;
      }
    }

    cout << ans << endl;
  }
  return 0;
}