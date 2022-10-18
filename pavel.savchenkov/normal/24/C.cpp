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

int M[2 * (int)1e5 + 10][2];
int A[2 * (int)1e5 + 10][2];
int n; i64 j;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> j;
  j = j % (n + n);
  cin >> M[0][0] >> M[0][1];

  forn(i, n)
   scanf("%d%d", &A[i][0], &A[i][1]);

  for (int i = 1; i <= n + n; i++)
   for (int z = 0; z < 2; z++)
    M[i][z] = 2 * A[(i - 1) % n][z] - M[i - 1][z];

  cout << M[j][0] << " " << M[j][1] << "\n";
  return 0;
}