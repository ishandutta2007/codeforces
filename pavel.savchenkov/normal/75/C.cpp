#include <cstdio>
#include <string>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a%b); }

int a, b, n;

vector <int> g;

int go(int low, int high)
{
  int l = 0; int r = (int)g.size();
  if  (g[l] > high) return -1;
  if  (g[r - 1] < low) return -1;
  while (l != r - 1)
  {
    int m = (l + r) >> 1;
    if  (g[m] <= high) l = m; else r = m;
  }
  if (g[l] <= high && g[l] >= low) return g[l];
  return -1;
}

int main()
{
    cin >> a >> b >> n;
    int d = gcd(a, b);

    for (int i = 2; i * i <= d; i++)
     if  (d % i == 0)
     {
       g.push_back(i);
       if  (d / i != i) g.push_back(d / i);
     }
    g.push_back(1);
    g.push_back(d);
    sort(g.begin(), g.end());
    
    for (int i = 0; i < n; i++)
    {
     int low, high; scanf("%d%d", &low, &high);
     printf("%d\n", go(low, high));
    }
    
    return 0;
}