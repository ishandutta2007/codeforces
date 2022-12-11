#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int main(){
  fastIO;
  int n,a,b;
  cin >> n >> a >> b;
  int rnd = 1;
  int x = 2;
  while (n > 1){
    a = (a + x - 1) / x;
    b = (b + x - 1) / x;
    if(a == b){
      if(n == 2)cout << "Final!";
      else cout << rnd;
      return 0;
    } 
    rnd++;
    n /= 2;
  }
  return 0;
}