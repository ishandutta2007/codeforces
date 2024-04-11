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
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int p[200];
int n;
int color[200];
int d[200];

void dfs(int v,int c){
	if (color[v]!=-1)
		return;
	color[v]=c;
	for (int i=0;i<n;i++)
		if (abs(v-i)==d[i] || abs(v-i)==d[v])
			dfs(i,c);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		{
			cin>>p[i];
			--p[i];
		}
	for (int i=0;i<n;i++)
		scanf("%d",&d[i]);
	memset(color,-1,sizeof(color));
	for (int i=0;i<n;i++)
		dfs(i,i);
	for (int i=0;i<n;i++)
		if (color[i]!=color[p[i]]){
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}