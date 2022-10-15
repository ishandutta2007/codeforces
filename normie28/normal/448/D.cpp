// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
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
//#define int long long 
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
const int mod = 1000000007;
long long int n, m, k;
int dp[2005][2005]={{0}};
/*********FUNCTIONS**************/
bool check(long long int mid){
	long long int sum=0;
	for(int i=1;i<=n;i++){
		sum+=min(m, mid/i);
	}
	return sum>=k;
}
 
/***********MAIN**************/

signed main(){ 
	cin>>n>>m>>k;
	long long int l=1, r=n*m;
	while(l<=r){
		long long int mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;
		}
		else {
			l=mid+1;
		}
	}
	cout<<r+1<<endl;
    
}