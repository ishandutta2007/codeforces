#include <bits/stdc++.h>

using namespace std;

int n;
string home;
multiset < string > stay, calc;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  cin >> n >> home;
  for(int i = 1; i <= n; ++i){
    string read;
    cin >> read;
    string u, v;
    for(int i = 0; i < 3; ++i){
      u += read[i];
      v += read[5 + i];
    }
    if(u == home){
      if(calc.count(v)){
        calc.erase(calc.lower_bound(v));
      }
      else{
        stay.insert(v);
      }
    }
    else{
      if(stay.count(u)){
        stay.erase(stay.lower_bound(u));
      }
      else{
        calc.insert(u);
      }
    }
  }
  if(stay.empty() && calc.empty()){
    cout << "home";
  }
  else{
    cout << "contest";
  }
  return 0;
}