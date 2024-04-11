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
#define i64 long long
#define ui64 unsigned long long
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
const int INT_INF = 0x7FFFFFFF;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFF;
const double PI = acos(-1.0);

using namespace std;

char s[202];

bool wub(int i)
{
  return s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B';
}

int main() {
//  freopen("in.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  gets(s);
  
  int i = 0; bool print = 0;

  while (s[i])
  {
   if  (wub(i)) { print = 0; i += 3; continue; }

   if  (print) 
    putchar(s[i++]);
   else
    print = 1, printf(" %c", s[i++]);
  }

  
  return 0;
}