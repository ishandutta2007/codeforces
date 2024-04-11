#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

ll gcd(ll a,ll b){if(a<b)swap(a,b);return b?gcd(b,a%b):a;}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  REP(cnum,t) {
    ll m,d,w;
    cin>>m>>d>>w;
    ll mn = min(m,d);
    if (d == 1) {
      cout<<0<<"\n";
      continue;
    }
    ll g = gcd(d-1, w);
    w /= g;
    ll r = mn % w;
    ll k = mn / w;
    cout << (w * k * (k-1) + 2 * r * k) / 2 << "\n";
  }
  return 0;
}