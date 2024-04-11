#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll gen[1005];


int main(){  
  gen[0]=1;
  gen[1]=1;
  set<ll>el;
  el.insert(1LL);
  for(int i = 2;i<=50;i++){
    gen[i]=gen[i-1]+gen[i-2];
    el.insert(gen[i]);
  }
  int n;
  cin >> n;
  for(int i = 1;i<=n;i++)
    cout << ((el.count((ll)i)) ? "O" : "o");
  return 0;
}