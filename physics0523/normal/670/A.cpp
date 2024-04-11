#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int bas=(n/7)*2,rem=n%7;
  cout << bas+max(0,rem-5) << ' ' << bas+min(2,rem) << '\n';
  return 0;
}