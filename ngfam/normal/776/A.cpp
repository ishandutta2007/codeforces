#include <bits/stdc++.h>

using namespace std;

int n, m;
string a, b;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
  #endif
  cin >> a >> b >> n;
  for(int i = 1; i <= n; ++i){
    cout << a << " " << b << endl;
    string c, d;
    cin >> c >> d;
    if(c == a){
      a = d;
    }
    else{
      b = d;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}