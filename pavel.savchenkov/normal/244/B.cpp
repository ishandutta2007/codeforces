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
#define all(A) ((A).begin(), (A).end())
#define sz(A) ((int)(A).size())
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 2 * (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);

using namespace std;

int C[20][20];
int R[12][11][11];
int n;
int c[11];
int cl = 0;
bool was[11];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;

  for (int i = 0; i <= 10; i++)
    C[i][i] = C[i][0] = 1;
  for (int i = 0; i <= 10; i++)
    for (int j = 1; j < i; j++) 
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];

  memset(R, 0, sizeof R);
  for (int len = 1; len <= 10; len++)
    for (int x = 0; x <= 9; x++)
        for (int y = 0; y <= 9; y++)
        {
            if  (x == y) {
                R[len][x][y] = 1 * (x != 0);
                continue;
            }

            for (int cntx = 1; cntx < len; cntx++)
            {
                if  (x == 0)
                    R[len][x][y] += C[len - 1][cntx];
                else
                    R[len][x][y] += C[len][cntx];
            }
        }

  int res = 0;

  while (n > 0) c[cl++] = n % 10, n /= 10;
  reverse(c, c + cl);
  
  for  (int len = 1; len < cl; len++)
    for (int x = 0; x <= 9; x++) 
        for (int y = x; y <= 9; y++)
            res += R[len][x][y];
  
  memset(R, 0, sizeof R);
  for (int len = 1; len <= 10; len++)
    for (int x = 0; x <= 9; x++)
        for (int y = 0; y <= 9; y++)
        {
            if  (x == y) {
                R[len][x][y] = 1;
                continue;
            }

            if  (len == 1)
                continue;

            R[len][x][y] = (1 << len) - 2;
        }  
  
  memset(was, 0, sizeof was);
  for (int i = 0; i < cl; i++)
  {
    for (int j = 0; j < c[i]; j++)
    {
        if  (j == 0 && i == 0) continue;
        int cntwas = 0;
        int x = j; int y = 0;
        for (int z = 0; z <= 9; z++)
            if  (was[z] || z == x) { if  (z != x) y = z; cntwas++; }
        if  (cntwas > 2) continue;

        if  (i == cl - 1) {
            res++;
            continue;
        }

        res += R[cl - i - 1][x][x];
        if  (cntwas == 2)
            res += R[cl - i - 1][x][y] + R[cl - i - 1][y][y];
        else
            for (; y <= 9; y++)
                if  (x != y)
                    res += R[cl - i - 1][x][y] + R[cl - i - 1][y][y];
    }                                                              
    was[c[i]] = 1;
  }
  
  int cnt = 0;
  for (int x = 0; x <= 9; x++)
    cnt += was[x];
    
  printf("%d\n", res + (cnt <= 2)); 
  return 0;
}