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

bool A[100000];

int main(int, char**){
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  FOR(i, n) A[i] = true;
  FOR(i, n-1){ ll x; cin >> x; A[x-1] = false; }
  FOR(i, n) if(A[i]){
    cout << i+1 << endl;
    return 0;
  }
  return 0;
}