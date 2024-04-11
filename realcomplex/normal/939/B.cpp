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
  ll n,k;
  cin >> n >> k;
  ll ans = n;
  
  ll typ = 1,am = 0;
  ll c;
  for(int i = 1;i<=k;i++){
    cin >> c;
    if(ans >= n % c){
      ans = n % c;
      typ = i;
      am = n / c;
    }
  }
  cout << typ << " " << am;
  return 0;
}