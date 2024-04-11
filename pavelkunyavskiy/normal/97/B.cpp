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

#define x first
#define y second

using namespace std;

typedef long long int64;
typedef long double ld;


pair<int,int> a[2500000];
int n;


void solve(int l,int r){
	if (l >= r-1)
		return;
	solve(l,(l+r)/2);
	solve((l+r)/2,r);
	int x = a[(l+r)/2].x;
	for (int i=l;i<r;i++)
		a[n++] = mp(x,a[i].y);	
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d %d",&a[i].x,&a[i].y);
	sort(a,a+n);
	solve(0,n);
	sort(a,a+n);
	n = unique(a,a+n) - a;
	printf("%d\n",n);	
	for (int i=0;i<n;i++)
		printf("%d %d\n",a[i].x,a[i].y);
	return 0;
}