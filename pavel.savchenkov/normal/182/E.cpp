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
const int mod = 1000000007;

using namespace std;
int a[2][110];
int n,l;
int d[10100][110][2];

void add(int &a,int b)
{
    a += b;
    if (a > mod) a -= mod;
}

int main() {
  memset(d,0,sizeof(d));
  cin >> n >> l;
  forn(i,n)
    scanf("%d%d",&a[0][i],&a[1][i]);
  forn(i,n)
    { d[a[1][i]][i][0] = 1; if (a[0][i] != a[1][i]) d[a[0][i]][i][1] = 1; }
  
  forn(len,l+1)
    forn(last,n)
        forn(rev,2)
            forn(next,n)
                forn(nrev,2)
                    if (next != last)
                    {
                        if (a[0][next] == a[1][next] && nrev == 1) continue;
                        if (a[0][last] == a[1][last] && rev == 1) continue;
                        
                        if (a[nrev][next] == a[1-rev][last]) 
                         add(d[len + a[1-nrev][next]][next][nrev], d[len][last][rev]); 
                    }
  
  int res = 0;
  for (int last = 0; last < n; last++)
    for (int rev = 0; rev < 2; rev++)
        add(res,d[l][last][rev]);

  cout << res << endl;
  return 0;
}