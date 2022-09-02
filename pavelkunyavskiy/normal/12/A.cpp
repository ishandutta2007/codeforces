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

char a[3][3];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  for (int i=0;i<3;i++)
  	for (int j=0;j<3;j++)
  		scanf(" %c ",&a[i][j]);
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if (a[i][j]!=a[2-i][2-j])
				{
					printf("NO\n");
					return 0;
				} 
	printf("YES\n");
  return 0;
}