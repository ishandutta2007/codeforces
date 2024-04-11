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
/***********MACROS***************/
#define int long long int
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
/*********VARIABLE****************/
using namespace std;
int64_t x,i,j,n,m,k,l,q,t,t1,a,b,dp[100001],ds[100001],maxmiss,maxx;
vector <int64_t> all;
/*********FUNCTIONS**************/
int powom(int a,int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1)
            result = result * a;
        a = a * a;
        b >>= 1;
    }
    return result;
}
/***********MAIN**************/
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for (i=1;i<=n;i++) {cin>>x; all.push_back(x);}
	sort(all.begin(),all.end());
	maxx=all[n-1];
	for (i=0;i<n;i++) {maxmiss+=maxx-all[i];}
	if (maxx<=maxmiss) x=maxx; else
	x=maxx+((maxx-maxmiss-1)/(n-1))+1;
	if (x<maxx) x=maxx;
	cout<<x;
}
//.........