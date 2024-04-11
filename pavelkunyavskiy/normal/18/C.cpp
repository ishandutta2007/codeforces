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

int a[110000];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf("%d",&n);
  int sum=0;
  for (int i=0;i<n;i++)
  {
  	scanf("%d",&a[i]);
  	sum+=a[i];
  }
  
  int suml=0;
  int ans=0;
  
  for (int i=0;i<n-1;i++){
  	suml+=a[i];
  	if (suml==sum-suml)
  		ans++;
  }
  
  cout<<ans;
  return 0;
}