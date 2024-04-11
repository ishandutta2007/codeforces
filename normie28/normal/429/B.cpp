// Thanks to robs77 for this template
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
#define inf 100000000000000000 
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
//#define mod 1000000007
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
const int N=1005;
int f1[N][N],f2[N][N],f3[N][N],f4[N][N];
int n,m;
int a[N][N];
/*********FUNCTIONS**************/
/***********MAIN**************/

signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        	scanf("%d",&a[i][j]);
 
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	memset(f3,0,sizeof(f3));
	memset(f4,0,sizeof(f4));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        	f1[i][j]=a[i][j]+max(f1[i-1][j],f1[i][j-1]);
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
        	f2[i][j]=a[i][j]+max(f2[i+1][j],f2[i][j+1]);
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
        	f3[i][j]=a[i][j]+max(f3[i+1][j],f3[i][j-1]);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
        	f4[i][j]=a[i][j]+max(f4[i-1][j],f4[i][j+1]);
    int x=0;
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++)
        x=max(x,f1[i][j-1]+f2[i][j+1]+f3[i+1][j]+f4[i-1][j]),
        x=max(x,f1[i-1][j]+f2[i+1][j]+f3[i][j-1]+f4[i][j+1]);
    
    printf("%d\n",x);
}