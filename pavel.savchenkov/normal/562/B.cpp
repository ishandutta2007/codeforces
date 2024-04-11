//#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

#define ford(i, n) for (int i = (int) n - 1; i >= 0; --i)
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define pb push_back
#define sz(c) ((int) (c).size())
#define fst first
#define snd second
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define left ________________left
#define right _______________right
#define hash ________________hash
#define y1 __________________y1

#define FILE_NAME ""

const int MAXN = 1e6 + 10;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int cnt[MAXN];
int dp[MAXN];
int n;

int main() {
#ifdef DEBUG
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n;
  forn(i, n) {
    int a;
    scanf("%d", &a);
    ++cnt[a];
  }

  for (int i = 1; i < MAXN; ++i) {
    dp[i] = max(dp[i], cnt[i]);
    for (int j = i * 2; j < MAXN; j += i) {
      dp[j] = max(dp[j], dp[i] + cnt[j]);
    } 
  }

  cout << *max_element(dp, dp + MAXN) << endl;

  return 0;
}