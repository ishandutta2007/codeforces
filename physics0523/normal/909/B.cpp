#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  // https://oeis.org/A002620
  n+=1;
  cout << (n*n)/4 << "\n";
  return 0;
}