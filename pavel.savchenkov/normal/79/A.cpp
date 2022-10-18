//HACK ME, PLEASE! ^_^
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

bool go(int x, int y, bool who = 0)
{
    if  (!who)
    {
        if  (x >= 2 && y >= 2) return !go(x - 2, y - 2, 1);
        if  (x >= 1 && y >= 12) return !go(x - 1, y - 12, 1);
        if  (y >= 22) return !go(x, y - 22, 1);
        return 0;
    }

    if  (y >= 22) return !go(x, y - 22, 0);
    if  (x >= 1 && y >= 12) return !go(x - 1, y - 12, 0);
    if  (x >= 2 && y >= 2) return !go(x - 2, y - 2, 0);
    return 0;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  int x, y;
  cin >> x >> y;
  puts(go(x, y) ? "Ciel" : "Hanako");
  return 0;
}