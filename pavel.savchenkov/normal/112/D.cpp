#include <cstdio>
#include <iostream>
#define i64 long long
#define forn(i,n) for (int (i)=0;(i)<(n);i++)
using namespace std;

int main() {
  int n; cin >> n;
  int last[100500];
  forn(i,100010) last[i] = -1;
  
  forn(i,n)
  {
   int x,y;
   scanf("%d%d",&x,&y);
   int res = 0;
   
   for(int j=1; j*j<=x; j++)
   {
    if  (x % j == 0)
    {
     if (last[x/j]< i - y) res++;
     last[x/j] = i;
     if  (x/j != j && last[j] < i - y) res++;
     last[j] = i;
    }
   }
   
   printf("%d\n",res);
  }
  
  return 0;
  }