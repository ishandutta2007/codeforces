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

const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

int months[][12] =
{
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int a, b, c;
int A[3];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d.%d.%d\n", &a, &b, &c);
  scanf("%d.%d.%d", &A[0], &A[1], &A[2]);
  sort(A, A + 3);

  bool can = 0;
  do
  {
    bool year = (A[2] % 4 == 0);

    if  (A[1] > 12 || months[year][A[1] - 1] < A[0]) continue;

    int AA[3]; forn(i, 3) AA[i] = A[i];

    AA[2] += 18;
    if  (AA[0] == 29 && AA[1] == 2 && A[2] % 4 == 0) AA[0] = 1, AA[1] = 3;

    if  (AA[2] > c) continue;
    if  (AA[2] < c) { can = 1; continue; }
    if  (AA[1] > b) continue;
    if  (AA[1] < b) { can = 1; continue; }
    if  (AA[0] > a) continue;
    if  (AA[0] <= a) can = 1;

  } while (next_permutation(A, A + 3));

  puts(can ? "YES" : "NO");
  return 0;
}