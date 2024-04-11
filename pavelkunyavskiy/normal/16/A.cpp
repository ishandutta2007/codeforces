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

char a[110][110];;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n,m;
  scanf("%d %d",&n,&m);
  for (int i=0;i<n;i++)
  	for (int j=0;j<m;j++)
  		scanf(" %c ",&a[i][j]);
  for (int i=0;i<n;i++)
  	for (int j=0;j<m;j++)
  		if (a[i][j]!=a[i][0]){
  			printf("NO\n");
  			return 0;
  		}
  for (int i=0;i<n-1;i++)
  	if (a[i][0]==a[i+1][0])
  		{
  			printf("NO\n");
  			return 0;
  		}
  printf("YES\n");
  return 0;
}