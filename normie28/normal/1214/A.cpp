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
#define ll  int64_t 
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
ll a[3],n,i,j,x,y,minn=0;
/*********FUNCTIONS**************/

 
/***********MAIN**************/

signed main(){
	cin>>n>>a[1]>>a[2]; a[2]*=5;
	if (n==0) {cout<<0; return 0;}
	minn=n;
	for (i=0;i<=n/a[1];i++) {x=n-(i*a[1]); x%=a[2]; if (x<minn) minn=x;}
	cout<<minn;
}

//