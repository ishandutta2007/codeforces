#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <tuple>

using namespace std;

#define ll long long
#define ull unsigned long long

#define FOR(i, n) for(ll i = 0; i < (n); ++i)
#define FORU(i, j, k) for(ll i = j; i <= (k); ++i)
#define FORD(i, j, k) for(ll i = j; i >= (k); --i)

#define pf push_front
#define pb push_back

#define mp make_pair
#define f first
#define s second

bool A[300];

int main(int, char**){
  ios::sync_with_stdio(false);
  ll a[3]; cin >> a[0] >> a[1] >> a[2];
  ll b[3]; cin >> b[0] >> b[1] >> b[2];
  ll n; cin >> n;
  ll aa = accumulate(a, a+3, 0);
  ll bb = accumulate(b, b+3, 0);
  cout << ((n >= (aa+4)/5+(bb+9)/10) ? "YES" : "NO") << endl;
  return 0;
}