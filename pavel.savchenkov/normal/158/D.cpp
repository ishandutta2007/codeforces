//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define pb push_back
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define f first
#define s second
using namespace std;
int t[30000];
int ans = -2000000000;

int main() {
  int n; 
  scanf("%d",&n);
  forn(i,n) scanf("%d",&t[i]);
  
  for (int i=1;i<n; i++)
  {
   if (n % i != 0) continue;
   if (n / i < 3) break; 
   for (int first=0; first<i; first++)
    {
     int step = i; int sum = 0;
     for (int j=first; j<n; j+=step)
      sum += t[j];
     ans = max(ans,sum);
    } 
  }
  
  cout << ans << endl;
  return 0;
}