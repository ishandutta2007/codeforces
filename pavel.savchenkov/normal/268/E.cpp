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
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = 5 * (int) 1e4 + 10;

using namespace std;

struct song {
  int l, p;

  song (int l = 0, int p = 0) : l(l), p(p) {};

  friend bool operator <(const song & a, const song & b) {
    return a.l * a.p * (100 - b.p) > b.l * b.p * (100 - a.p);
  }
};

int n;
song s[MAXN];

double time_all;
double time_songs;

double calc() {
  time_all = time_songs = 0.0;

  for (int i = 0; i < n; i++) {
    double p = (double)s[i].p / 100.0;
    double l = (double)s[i].l;
    time_all = p * (time_all + l) + (1.0 - p) * (time_all + l + time_songs);
    time_songs = p * (time_songs + l) + (1.0 - p) * time_songs;
  }

  return time_all;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++)
    scanf("%d%d", &s[i].l, &s[i].p);

  sort(s, s + n);
  
  printf("%.10lf\n", calc());
  return 0;
}