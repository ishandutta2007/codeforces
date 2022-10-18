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

const double eps = 1e-9;
const int int_inf = 2147483640;
const i64 i64_inf = 9223372036854775800ll;
const double pi = acos(-1.0);

using namespace std;

int a[200500];
int b[200500];
int n;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n)
   scanf("%d",&a[i]);
  int x;
  forn(i, n)
   scanf("%d",&x), b[x] = i;
  
  forn(i, n)
   a[i] = b[a[i]];
  int j = 1;
  while (a[j] > a[j - 1]) j++;
  
  printf("%d\n",n - j);
  return 0;
}