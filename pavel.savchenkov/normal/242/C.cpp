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
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define y1 fucking_y1
#define y0 sdfdsf

const double EPS = 1e-9;
const int INT_INF = 2 * (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);
const int SZ = 1 << 20;

using namespace std;

int dx[3] = { 1, -1, 0 };
int dy[3] = { 1, -1, 0 };

int x0, y0, x1, y1;
int n;
pair <int, int> all[100500];
int allsz = 0;

int d[SZ];
bool was[SZ];
bool m[SZ];

int hash(int x, int y) {
    return (x * 1000000009 + y) & (SZ - 1);
}

void put(int x, int y) {
    m[hash(x, y)] = 1;
}

int ID(int x, int y) {
    int h = hash(x, y);
    if  (!m[h]) return -1;
    return h;
}

int main() {
// freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> x0 >> y0 >> x1 >> y1 >> n;
  memset(m, 0, sizeof m);

  int sum = 0;
  forn(i, n) {
    int r, a, b;
    scanf("%d%d%d", &r, &a, &b);
    sum += b - a + 1;
    for (int j = a; j <= b; j++)
         put(r, j);
  }

  assert(sum <= 100000);
  
  memset(was, 0, sizeof was);
  forn(i, SZ) d[i] = INT_INF;
  d[ID(x0, y0)] = 0;
  queue <pii> q;
  q.push(mp(x0, y0));
  was[ID(x0, y0)] = 1;
  
  while (!q.empty()) {
    int x = q.front().f;
    int y = q.front().s;
    q.pop();
    int curid = ID(x, y);

    forn(j, 3)
        forn(i, 3) {
            if  (i == j && i == 2) break;
            int id = ID(x + dx[i], y + dy[j]);
            if  (id == -1 || was[id]) continue;
            was[id] = 1;
            d[id] = d[curid] + 1;
            
            if  (x + dx[i] == x1 && y + dy[j] == y1) {
                printf("%d\n", d[curid] + 1);
                return 0;
            }
            
            q.push(mp(x + dx[i], y + dy[j]));
        }
  }

  puts("-1");
  return 0;
}