#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
  if (b == 0)
    return a;
  return gcd(b, a % b); 
}

int main(){
  int n;
  cin >> n;
  vector<long long> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  sort(A.begin(), A.end());
  long long d = 0;
  for (int i = 0; i + 1 < n; ++i)
    d = gcd(d, A[i + 1] - A[i]);
  long long res = 0;
  for (int i = 0; i < n; ++i)
    res += A[n - 1] - A[i];
  long long ansy = res, ansz = 1;
  long long z = 1;
  while (z * z <= d){
    if (d % z == 0){
       if (res / z < ansy){
         ansy = res / z;
         ansz = z;
       }
       if (res / (d / z) < ansy){
         ansy = res / (d / z);
         ansz = d / z;
       }
    }
    z += 1;
  }
  cout << ansy << ' ' << ansz;
  return 0;
}