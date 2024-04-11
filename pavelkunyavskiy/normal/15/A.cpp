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

pair<int,int> x[1100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n,t;
  scanf("%d %d",&n,&t);
  for (int i=0;i<n;i++)
  {
  	scanf("%d %d",&x[i].first,&x[i].second);
  	x[i].first*=2;
  	x[i].second*=2;
  }
  t*=2;
  sort(x,x+n);
  int ans=0;
  for (int i=0;i<n;i++){
  	if (i==0 || (x[i].first-x[i-1].first>=x[i].second/2+x[i-1].second/2+t))
  		ans++;
  	if (i==n-1 || (x[i+1].first-x[i].first>x[i].second/2+x[i+1].second/2+t))
  		ans++;
  }
  printf("%d\n",ans);
  return 0;
}