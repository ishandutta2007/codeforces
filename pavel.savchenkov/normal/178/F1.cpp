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
int n,k;
char s[200][600];
int a[200][200];
int r[200];
int res = -1;

int calc(int x,int y)
{
    for (int i=0; s[x][i] && s[y][i]; i++)
        if (s[x][i] != s[y][i]) return i;
    return min( (int)strlen(s[x]), (int)strlen(s[y]) );
}

void foo (int len)
{
    if (len == k)
    {
        int ans = 0;
        forn(i, len)
            foran(j, i, len)
                ans += a[r[i]][r[j]];
        res = max(res, ans);
        return;
    }
    int last = -1; if (len != 0) last = r[len - 1];
    for (int next = last + 1; next < n; next++)
        r[len] = next, foo(len + 1);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d%d\n",&n,&k);
  forn(i, n)
    gets(s[i]);
//  forn(i, n)
//  puts(s[i]);
  forn(i, n)
    foran(j, i+1, n)
        a[i][j] = calc(i, j);
  /*
  forn(i, n)
  {
    foran(j, i, n)
        cout << a[i][j] << " ";
    cout << endl;
  }
  */
  foo(0);
  
  cout << res << endl;
  return 0;
}