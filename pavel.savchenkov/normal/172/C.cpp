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
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
struct person
{
    int t,x,id;
    person() {};
};
int w[100500];
person d[100500];
int n,m;
int timer = 0;

bool cmp(person a,person b) { return a.x < b.x;}

void go(int l,int r)
{
    if (r >= n) r = n - 1;
    int s = 0; int k = 1; if (timer < d[r].t) timer = d[r].t; 
    sort(d+l,d+r+1,cmp);
        
    foran(i,l+1,r+1)
        if (d[i].x != d[i-1].x)
        {
            timer += d[i-1].x - s + 1 + k / 2;
            int res = timer - 1 - k / 2;
            s = d[i-1].x;
            k = 1;
            int j = i - 1;
            while (j >= l && d[j].x == d[i-1].x) w[d[j].id] = res,j--;
        } else k++;

    int res = timer + d[r].x - s;
    int j = r; 
    while (j >= l && d[j].x == d[r].x) w[d[j].id] = res,j--;
    timer += d[r].x + d[r].x - s + 1 + k / 2;
}

int main() {
  cin >> n >> m;
  forn(i,n) scanf("%d%d",&d[i].t,&d[i].x), d[i].id = i + 1;
  
  for (int i=0; i<n; i += m)
    go(i,i+m-1);
  
  for (int i=1; i<=n; i++)
      printf("%d ",w[i]);
  return 0;
}