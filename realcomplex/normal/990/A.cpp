#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  ll n,m;
  ll a,b;
  cin >> n >> m >> a >> b;
  if(n % m == 0)
    cout << "0";
  else if(n < m){
    cout << min((m - n) * a,n * b); 
  }
  else{
    ll d = n/m;
    d ++ ;
    d *= m;
    d -= n;
    cout << min((n%m) * b, d*a);
  }
  return 0;
}