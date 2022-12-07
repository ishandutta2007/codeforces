#include <bits/stdc++.h>

using namespace std;

int main(){
  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
    
  set < long long > ans;
  
  for(int i = 1; i * i <= n; ++i) {
    if(n % i == 0) {
      long long x = i;
      long long y = n / i;
      ans.insert(y + (y * (y - 1) / 2) * x);
      ans.insert(x + (x * (x - 1) / 2) * y);
    }
  }
  
  for(long long r : ans) cout << r << " ";
  
  return 0;
}