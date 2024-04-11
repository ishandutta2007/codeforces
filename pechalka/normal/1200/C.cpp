#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

long long gcd(long long a, long long b){
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main(){
  long long A[2];
  cin >> A[0] >> A[1];
  long long B[2];
  B[0] = A[0] / gcd(A[0], A[1]);
  B[1] = A[1] / gcd(A[0], A[1]);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i){
    int sx, ex;
    long long sy, ey;
    cin >> sx >> sy >> ex >> ey;
    --sx;
    --sy;
    --ex;
    --ey;
    if (sy / B[sx] == ey / B[ex])
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }
  return 0;
}