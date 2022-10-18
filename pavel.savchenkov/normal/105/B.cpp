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
int b[30]; int l[30];
int n,k,A;
double ans = 0.0;
int c[10];

double get()
{
    double res = 0.0;
    for (int mask=0; mask<(1<<(n)); mask++)
    {
        double ver = 1.0; int win = 0; int sum = 0;
        forn(i,n)
            if (mask&(1<<i)) ver *= (double)l[i]/100.0, win++; else ver *= 1.0 - (double)l[i]/100.0, sum += b[i];
        if (win >= n/2 + 1) res += ver; else
            res += ver * (double)A/(A + sum);
    }
    return res;
}

void gen(int len = 0,int sum = 0) 
{
    if (len == n)
    {
        forn(i,n) l[i] += c[i] * 10;
//      forn(i,n) cout << l[i] << " "; puts("");
        ans = max(ans,get()); 
        forn(i,n) l[i] -= c[i] * 10;
        return;
    }
    if (sum > k) return;
    for (int i=0; i<=k-sum; i++)
        if (i*10 + l[len] <= 100) c[len] = i, gen(len+1,sum+i);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> k >> A;
  forn(i,n) cin >> b[i] >> l[i];
  gen();
  printf("%.10lf\n",ans);
  return 0;
}