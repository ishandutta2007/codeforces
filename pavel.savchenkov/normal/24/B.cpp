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
const i64 i64_inf = 1000000000000000000ll;
const double pi = acos(-1.0);

using namespace std;
struct racer
{
    string name;
    int cnt[60];
    int sum;
    racer(string _n="", int _sum=0) { name=_n; memset(cnt,0,sizeof(cnt)); sum=_sum; }   
};

int p[10] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };
vector <racer> r;
int t, n;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> t;
  forn(i, t)
  {
    scanf("%d\n",&n);
    forn(j, n)
    {
        string name; getline(cin, name);
        bool was = 0;
        forn(z, r.size())
            if (r[z].name == name) { r[z].cnt[j]++; if (j < 10) r[z].sum += p[j]; was = 1; break; }
        if (was) continue;
        if (j < 10) r.pb( racer(name,p[j]) ); else r.pb( racer(name) );
        r.rbegin()->cnt[j]++;
    }
  }
  
  int m = 0;
  foran(i, 1, r.size())
  {
    if (r[i].sum > r[m].sum) m = i;
    if (r[i].sum != r[m].sum) continue;
    forn(j, 55)
        if (r[m].cnt[j] < r[i].cnt[j]) { m = i; break; } else
            if (r[m].cnt[j] > r[i].cnt[j]) break;
  }
  
  cout << r[m].name << endl;
  
  m = 0;
  foran(i, 1, r.size())
  {
    if (r[i].cnt[0] > r[m].cnt[0]) m = i;
    if (r[i].cnt[0] != r[m].cnt[0]) continue;
    if (r[i].sum > r[m].sum) m = i;
    if (r[i].sum != r[m].sum) continue;
    foran(j, 1, 55)
        if (r[m].cnt[j] < r[i].cnt[j]) { m = i; break; } else
            if (r[m].cnt[j] > r[i].cnt[j]) break;
  }
  
  cout << r[m].name << endl;
  
  return 0;
}