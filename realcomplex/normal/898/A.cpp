#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int k = n-(n%10);
  int v = n+10-(n%10);
  cout << ((n-k<v-n) ? k : v);
  return 0;
}