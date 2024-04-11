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
#include <cassert>
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
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define modLim (int)(pow(10,9)+7)
//#define mod 1000000007
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
map<int,int> m;
/*********FUNCTIONS**************/

/***********MAIN**************/
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >>x;
		if(x!=0)
			m[x]++;
	}
	long long ans = 0;
	bool ok = 1;
	for(auto p:m){
		if(p.second>=3) ok= 0;
		else ans+=p.second/2;
	}
	if(!ok)ans = -1;
	cout<<ans<<"\n";
     
}