// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
#define int long long 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 

/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
const int maxn = 100000+10;
int a[maxn];
int v[maxn];
int n;
/*********FUNCTIONS**************/
bool check(long double t)
{
	long double left=a[0]*1.0-t*v[0];
	long double right=a[0]*1.0+t*v[0];
	for(int i=1;i<n;i++)
	{
		long double l=a[i]*1.0-t*v[i]*1.0;
		long double r=a[i]*1.0+t*v[i]*1.0;
		if(l>right||r<left)return false;
		left=std::max(left,l);
		right=std::min(right,r);
	}
	return true;
}
 
/***********MAIN**************/

signed main(){
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		double l=0,r=1e9;
		while(r-l>1e-6)
		{
			long double mid=(r+l)/2;
			if(check(mid))
			{
				r=mid;
			}
			else
			{
				l=mid;
			}
		}
		printf("%.8lf\n",r);
	}
}

//