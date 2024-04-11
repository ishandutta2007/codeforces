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
  ll n,a,b,c;
  cin >> n >> a >> b >> c;
  if(n % 4 == 0)
    cout << 0;
  else if( n % 4 == 1)
    cout << min(a * 3, min(c, a + b));
  else if(n % 4 == 2)
    cout << min(a * 2, min(b, c * 2));
  else
    cout << min(min(b + c, a ), c * 3);
  return 0;
}