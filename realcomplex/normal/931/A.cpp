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

ll f(ll x){
  return (x * (x + 1)) / 2;
}

int main(){
  fastIO;
  ll a,b;
  cin >> a >> b;
  if(a >b)
    swap(a,b);
  ll l = (a + b ) / 2;
  cout << f(l-a) + f(b-l);
  return 0;
}