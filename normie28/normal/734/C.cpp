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
int x,s,n,m,k;
int  a[200005], b[200005], c[200005], d[200005];
/*********FUNCTIONS**************/

 
/***********MAIN**************/

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    cin >> x >> s;
    for(int i=1; i<=m; i++){
    	cin >> a[i];
    }
    for(int i=1; i<=m; i++) cin >> b[i];
    for(int i=1; i<=k; i++) cin >> c[i];
    for(int i=1; i<=k; i++) cin >> d[i];
    ll ans=1ll*(n-c[upper_bound(d+1,d+k+1,s)-d-1])*x;
    for(int i=1; i<=m; i++){
    	if(b[i]>s) continue;
    	else{
    		int res = upper_bound(d+1, d+k+1, s - b[i]) - d - 1;
            ans = min(ans, 1ll*(n-c[res])*a[i]);
    	}
    }
    cout << ans;
    return 0;
}

//