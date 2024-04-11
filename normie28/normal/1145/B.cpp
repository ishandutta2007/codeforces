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
ll n;
ll kanban[100];
/*********FUNCTIONS**************/

/***********MAIN**************/

signed main(){ 
	kanban[2]=kanban[3]=kanban[4]=kanban[5]=kanban[6]=kanban[8]=kanban[12]=kanban[30]=kanban[31]=kanban[32]=kanban[35]=kanban[43]=kanban[46]=kanban[52]=kanban[64]=kanban[86]=1;
	cin>>n;
	if(kanban[n]) cout<<"YES"; else cout<<"NO";
}