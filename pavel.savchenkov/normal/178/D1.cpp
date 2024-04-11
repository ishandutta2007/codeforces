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
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
int n;
int a[20];
int s;
int c[4][4];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n * n)
      scanf("%d",&a[i]), s += a[i];
  s /= n;
  sort(a, a + n * n);
  
  do
  {
//  forn(i, n*n) cout << a[i] << " "; cout << endl;
    
    forn(i, n * n)
        c[i / n][i % n] = a[i];
    bool f = 1;

    forn(i, n)
    {
        int sum = 0;
        forn(j, n)
            sum += c[i][j];
        if (sum != s) { f = 0; break; }
    }
    if (!f) continue;
    forn(i, n)
    {
        int sum = 0;
        forn(j, n)
            sum += c[j][i];
        if (sum != s) { f = 0; break; }
    }
    if (!f) continue;
    int sum = 0;
    forn(i, n)
        sum += c[i][i];
    if (sum != s) continue;
    sum = 0;
    forn(i, n)
        sum += c[i][n-i-1];
    if (sum != s) continue;
    
    cout << s << endl;
    forn(i, n)
    {
        forn(j, n)
            cout << c[i][j] << " ";
        cout << endl;
    }
    break;
  } while (next_permutation(a,a + n * n));
  
  return 0;
}