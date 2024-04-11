// Credit to robs77 for this template
/***********HEADER***************/
#include <bits/stdc++.h>
using namespace std;
/***********MACROS***************/
//#define int long long 
#define ll int64_t 
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
struct bd {ll v; ll c;};
typedef pair<int,int> ii;
/******************************/
const ll po[26]={1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1};
ll n,i,j,x,y,z,minn=0,t,pr,a,b,k;
bd all[300001]; bd h;
ll dp[300001][3];
string s;
/*********FUNCTIONS**************/
 
 
/***********MAIN**************/
 
signed main()
{ 
	cin>>s;
	n=s.length();
	for (i=0;i<n;i++) x+=po[s[i]-65];
	if ((x==0)or(x==n)) cout<<"YES"; else cout<<"NO";
}