#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  long long a, b, c;

  cin >> a >> b >> c;
  c += c;

  if(a == b) cout << c + a + b;
  else cout << c + min(a, b) * 2 + 1;

  return 0;
}