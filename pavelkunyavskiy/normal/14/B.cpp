#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

int kol[1010];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n,x0;
  cin>>n>>x0;
  for (int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    if (a>b)
        swap(a,b);
    for (int j=a;j<=b;j++)
        kol[j]++;
  }
  int d=(1<<30);
  for (int i=0;i<1010;i++)
    if (kol[i]==n)
        d=min(abs(x0-i),d);
  if (d==(1<<30))
    printf("-1\n");
    else
      printf("%d\n",d);
  return 0;
}