#include <bits/stdc++.h>

using namespace std;

int main(){
  int b, k;
  cin >> b >> k;
  int a;
  b %= 2;
  int r = 1;
  int sum = 0;
  vector<int> t;
  for(int i = 0 ; i < k ; i ++ ){
    cin >> a;
    t.push_back(a);
  }
  reverse(t.begin(), t.end());
  for(int x : t){
    sum += (x%2) * r;
    r *= b;
  }
  if(sum % 2 == 0) cout << "even\n";
  else cout << "odd\n";
  return 0;
}