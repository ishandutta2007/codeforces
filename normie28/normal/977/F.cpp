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
#define mod 1000000007
#define inf 100000000
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
#define MAX 200005
ll v[MAX]={0};
/*********FUNCTIONS**************/
void fnc(int n)
{
  map<ll,int>mp;
  int mx=0,end=-1;
  for(int i=0;i<n;i++)
  {
    mp[v[i]]=mp[v[i]-1]+1;
    if(mp[v[i]]>mx) {mx=mp[v[i]];end=v[i];}
  }
  cout<<mx<<endl;
  int start=end-mx+1;
  for(int i=0;i<n && start<=end;i++)
  {
    if(start==v[i]) {cout<<i+1<<" ";start++;}  
  }
}
/***********MAIN**************/

signed main(){ 
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int m,t;
cin>>m;
for(int i=0;i<m;i++) cin>>v[i];
fnc(m);
cout<<endl;

}