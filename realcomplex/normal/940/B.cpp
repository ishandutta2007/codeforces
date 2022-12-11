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

ll get(ll x,ll y){
  return x-(x/y);
}

int main(){
  fastIO;
  ll n,k,a,b;
  cin >> n >> k >> a >> b;
  if(k == 1){
    cout << (n-1) * a;
    return 0;
  }
  ll ans = 0;
  while(n > 1){
    if(n < k){
      ans += (n-1)*a;
      n=1;
      continue;
    }
    if(n%k!=0){
      ans +=(n%k)*a;
      n-=n%k;
      continue;
    }
    if(get(n,k)*a > b){
      ans+=b;
    }
    else{
      ans+=get(n,k)*a;
    }
    n/=k;
  }
  cout << ans;
  return 0;
}