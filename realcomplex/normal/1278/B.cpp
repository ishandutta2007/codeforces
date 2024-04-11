#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool check(ll t, int q){
  while(t >= 0 && q > 0){
    if(t >= q){
      t -= q;
    }
    q--;
  }
  return (t == 0);
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int tt = 0; tt < tc; tt ++ ){
    ll a, b;
    cin >> a >> b;
    if(a > b)
      swap(a, b);
    ll x = 0;
    while(a < b || ((a-b)%2 == 1)){
      x++;
      a += x;
    }
    a-=b;
    cout << x << "\n";
  }
  return 0;
}