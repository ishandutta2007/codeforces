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

int n, m, k;
int dx;

void isWin(int pos)
{
   if  (m != k) return;
   printf("Controller %d\n", pos); exit(0);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> k >> m; scanf("\n");
  string s; getline(cin, s);
  if  (s == "to tail") dx = 1; else dx = -1;
  scanf("\n");
  if  (m == n) dx = -1; else
   if  (m == 1) dx = 1;

  char c = getchar();
  for (int i = 1; c != '\n'; i++, c = getchar())
  {
   //   cout << c << endl;
      if  (c == '0')
      {
        if  (k < m && k > 1) k--;
        if  (k > m && k < n) k++;
        m += dx;
        if  (m == n) dx = -1; else if  (m == 1) dx = 1;
      } else
      {
          m += dx;
          if  (m == n) k = 1;
           else if  (m == 1) k = n; else
            if  (dx == 1) k = 1; else
             if  (dx == -1) k = n;
          if  (m == n) dx = -1; else if  (m == 1) dx = 1;
      }

    //  cout << m << " " << k << endl;
      isWin(i);
  }

  cout << "Stowaway\n";
  return 0;
}