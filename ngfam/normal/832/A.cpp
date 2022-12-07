#include <bits/stdc++.h>

using namespace std;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  long long n, k;
  cin >> n >> k;
  long long ans = n / k;
  if(ans % 2 == 1){
    cout << "YES";
  }
  else{
    cout << "NO";
  }
  return 0;
}