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


int main(int, char**){
  ios::sync_with_stdio(false);
  char c; cin >> c;
  set<char> a;
  while(c != '}'){
    cin >> c; if(c != '}') a.insert(c);
    if(c != '}') cin >> c;
  }
  cout << a.size() << endl;
  return 0;
}