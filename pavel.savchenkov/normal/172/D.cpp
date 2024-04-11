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
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
int c[10000010]; 
bool isSq[10000010];
i64 res = 0;
int a,n;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> a >> n;
  for (int i=a; i<=a+n-1; i++) c[i] = i;
  memset(isSq,0,sizeof(isSq));
  
  for (int i=2; i < a+n; i++)
    if (isSq[i])
    {
        for (int j=i; j<a+n; j += i)
            c[j] = min(c[j],j/i);
        i64 I = i;
        if (I * I < (i64)(a+n)) isSq[i*i] = 1;
    } else
    {
        i64 I = i;
        if (I * I < (i64)(a+n)) isSq[i*i] = 1;
    }
  
  for (int i=a; i < a+n; i++)
    res += c[i];
  cout << res << endl;
  return 0;
}