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
#include <iomanip>
#include <cassert>
#include <queue>

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

ll R[1000];
ll C[1000];

ll RX[1000001];
ll CX[1000001];

int main(int, char**){
  ios::sync_with_stdio(false);
  ll n, m, k, p;
  cin >> n >> m >> k >> p;

  FOR(i, n) FOR(j, m) {
    ll x; cin >> x;
    R[i] += x;
    C[j] += x;
  }

  priority_queue<ll, vector<ll>, less<ll>> RQ;
  priority_queue<ll, vector<ll>, less<ll>> CQ;

  FOR(i, n) RQ.push(R[i]);
  FOR(i, m) CQ.push(C[i]);

  RX[0] = 0;
  FORU(i, 1, k){
    ll x = RQ.top();
    RQ.pop();
    RX[i] = RX[i-1] + x;
    RQ.push(x - m * p);
  }

  CX[0] = 0;
  FORU(i, 1, k){
    ll x = CQ.top();
    CQ.pop();
    CX[i] = CX[i-1] + x;
    CQ.push(x - n * p);
  }

  ll ma = -1e30;

  FOR(i, k+1){
    ma = max(ma, RX[i] + CX[k-i] - i * (k - i) * p);
  }
  cout << ma << endl;

  return 0;
}