#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int testc;
  cin >> testc;
  for(int i = 0 ; i < testc; i ++ ){
    ll n, d;
    cin >> n >> d;
    ll p = d;
    for(ll x = 1;;x++){
      if(x+((d+x)/(x+1)) > p) break;
      p=x+((d+x)/(x+1));
    }
    if(p<=n){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
  return 0;
}