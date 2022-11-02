#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>
 
using namespace std;
 
int main(){
  int n;
  cin >> n;
  long long mx = 0, sum = 0;
  for (int i = 0; i < n; ++i){
    long long x;
    cin >> x;
    mx = max(mx, x);
    sum += x;
  }
  if (sum >= 2 * mx && sum % 2 == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}