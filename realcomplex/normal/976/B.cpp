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
#define len(x) ((ll)(x).size())

int main(){
  fastIO;
  ll n,m,k;
  cin >> n >> m >> k;
  if(k < n){
    cout << 1+k << " " << 1 << "\n";
    return 0;
  }
  ll t = m - 1;
  k -= n - 1;
  ll dd = (k - 1) / t;
  ll r = (k - 1) % t;
  cout << n - dd << " ";
  if(dd % 2 == 0){
    cout << 2 + r;
  }
  else{
    cout << m - r;
  }
  return 0;
}