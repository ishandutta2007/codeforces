#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;



int main(){
  long long n, m;
  cin >> n >> m;
  if (n <= m){
    cout << n << endl;
    return 0;
  }
  long long a = 2 * (n - m); 
  long double xx = (sqrt(1 + 4 * a) - 1.0) / 2;
  // x -> min
  // (2x + 1) ^ 2 >= 1 + 4 * a
  long long x = xx;
  x += 1;
  while ((2*(x -1)+1) * (2*(x-1)+1) >= 1 + 4 * a) x--;  
  long long ans = m + x;
  cout << ans << endl;  
  return 0;
}