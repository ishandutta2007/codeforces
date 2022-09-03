#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <limits>
#include <stack>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#define ff first
#define ss second
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,m,n) for(int i=m;i<=n;i++)
#define all(i,j) for(i::iterator it=j.begin;it!=j.end;it++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int maxn=100005;
ll abs(int &a,int &b){return a>b?a-b:b-a;}
ll num;
vector<int>g[maxn];
int n,m;
int a[maxn];
ll best;
ll calc(int i)
{
   			sort(g[i].begin(),g[i].end());
   			int x=g[i][g[i].size()/2];
   			ll ans=0;
   			for(int j=0;j<g[i].size();j++){
					ans+=(abs(g[i][j],i)-abs(g[i][j],x));
			}
   			return ans;
}

int main()
{
 	scanf("%d%d",&n,&m);
 	for(int i=0;i<m;i++)scanf("%d",a+i);
 	for(int i=0;i<m-1;i++)num+=abs(a[i],a[i+1]);
 	for(int i=0;i<m;i++)
 	{ 
	 		int nx=i-1,ny=i+1;
	 		if(nx>-1&&a[nx]!=a[i])g[a[i]].pb(a[nx]);
	 		if(ny<m&&a[ny]!=a[i])g[a[i]].pb(a[ny]);
	}
	for(int i=1;i<=n;i++)if(g[i].size())best=max(best,calc(i));
	printf("%I64d\n",num-best);
	//system("pause");
	return 0;
}