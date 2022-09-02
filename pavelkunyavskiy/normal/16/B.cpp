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

pair<int,int> a[100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
	int m,n;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++)
		scanf("%d %d",&a[i].second,&a[i].first);
	sort(a,a+m);
	reverse(a,a+m);
	int64 ans=0;
	for (int i=0;i<m;i++){
		ans+=min(n,a[i].second)*1ll*a[i].first;
		n-=a[i].second;
		if (n<=0)
			break;
	}
	cout << ans <<endl;
  return 0;
}