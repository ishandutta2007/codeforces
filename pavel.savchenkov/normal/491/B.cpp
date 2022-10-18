#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
  return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

int n, m, c, h;
vll people_x;
vll people_y;

vll rest_x;
vll rest_y;

bool can(ll dist) {
  ll lx = (ll)-2e18;
  ll rx = (ll)2e18;

  forn(i, c) {
    lx = max(lx, people_x[i] - dist);
    rx = min(rx, people_x[i] + dist);
  }

  if  (lx > rx) {
    return false;
  }

  ll ly = (ll)-2e18;
  ll ry = (ll)2e18;

  forn(i, c) {
    ly = max(ly, people_y[i] - dist);
    ry = min(ry, people_y[i] + dist);
  }

  if  (ly > ry) {
    return false;
  }

  forn(i, h) {
    if  (lx <= rest_x[i] && rest_x[i] <= rx && ly <= rest_y[i] && rest_y[i] <= ry) {
      return true;
    }
  }  

  return false;
}              

int get(ll dist) {
  ll lx = (ll)-2e18;
  ll rx = (ll)2e18;

  forn(i, c) {
    lx = max(lx, people_x[i] - dist);
    rx = min(rx, people_x[i] + dist);
  }

  if  (lx > rx) {
    return false;
  }

  ll ly = (ll)-2e18;
  ll ry = (ll)2e18;

  forn(i, c) {
    ly = max(ly, people_y[i] - dist);
    ry = min(ry, people_y[i] + dist);
  }

  if  (ly > ry) {
    return false;
  }

  forn(i, h) {
    if  (lx <= rest_x[i] && rest_x[i] <= rx && ly <= rest_y[i] && rest_y[i] <= ry) {
      return i + 1;
    }
  }

  assert(0);
  return 0;
}

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  cin >> n >> m;

  cin >> c;
  people_x.resize(c);
  people_y.resize(c);
  forn(i, c) {
    int x, y;
    scanf("%d%d", &x, &y);
    people_x[i] = (x + y);
    people_y[i] = (x - y);  
  }

  cin >> h;
  rest_x.resize(h);
  rest_y.resize(h);
  forn(i, h) {
    int x, y;
    scanf("%d%d", &x, &y);
    rest_x[i] = (x + y);
    rest_y[i] = (x - y);  
  }

  ll L = -1ll;
  ll R = (ll)2e10;
  while (L != R - 1ll) {
    int M = (L + R) / 2ll;

    if  (can(M)) {
      R = M;
    } else {
      L = M;
    }
  }

  cout << R << endl;
  cout << get(R) << endl; 
  return 0;
}