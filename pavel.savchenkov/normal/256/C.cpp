#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define sqr(x) ((x) * (x))
#define sz(A) ((int)(A).size())
#define all(A) ((A).begin(), (A).end())
#define y1 asxfdsfsdsjhfgidf
#define y0 dsfgdfggdfjdhriwurehiw

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = 77777;
const int MAXNIM = (int) 1e6;

using namespace std;

int n;
set <int> s;
LL qs[MAXN+10];
int nim[MAXNIM+10];
int cnt[MAXNIM+10];

int GetL(LL a) {
  LL L = 1; LL R = (LL) 1e4;
  while (L != R - 1LL) {
    LL M = (L + R) >> 1LL;
    if  (M * M * M * M >= a) R = M; else L = M;
  }
  return (int) R;

  return (int) (ceil(sqrt(sqrt(a))));
}

int GetR(LL a) {
  LL L = 1; LL R = (LL) 1e6;
  while (L != R - 1LL) {
    LL M = (L + R) >> 1LL;
    if  (M * M <= a) L = M; else R = M;
  }
  return (int) L;

  return (int) (floor(sqrt(a)));
}

void remove(int x) {
  if  (cnt[x] == 0) return;
  cnt[x]--;
  if  (cnt[x] == 0)
    s.insert(x);
}

void add(int x) {
  if  (cnt[x] == 0)
    s.erase(x);
  cnt[x]++;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n; int new_n = 0;
  for (int i = 0; i < n; i++) {
    LL a; scanf("%I64d", &a);
    if  (a > 3LL) qs[new_n++] = a;
  }
  n = new_n;

  sort(qs, qs + n);

  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i <= MAXNIM; i++)
    s.insert(i);

  nim[0] = nim[1] = nim[2] = nim[3] = 0; nim[4] = 1;
  int L = 2; int R = 2; add(0);
  for (int i = 5; i <= MAXNIM; i++) {
    int curL = GetL(i); int curR = GetR(i);
    R = max(R, curL - 1);
    while (L < curL) remove(nim[L++]);
    while (R < curR) add(nim[++R]);

    nim[i] = *s.begin();
  }

  s.clear(); memset(cnt, 0, sizeof cnt);
  for (int i = 0; i <= MAXNIM; i++)
    s.insert(i);

  L = GetL(qs[0]); R = GetR(qs[0]);
  for (int i = L; i <= R; i++)
    add(nim[i]);
  int ans = *s.begin();

  for (int i = 1; i < n; i++) {
    int curL = GetL(qs[i]); int curR = GetR(qs[i]);
    R = max(R, curL - 1);
    while (L < curL) remove(nim[L++]);
    while (R < curR) add(nim[++R]);

    ans ^= *s.begin();
  }

  puts(ans == 0 || n == 0 ? "Rublo" : "Furlo");
  return 0;
}