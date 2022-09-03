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
#include <complex>
#include <cassert>
#include <numeric>
#include <valarray>
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
typedef queue<pii>qpii;
typedef queue<int>qi;
typedef queue<ll>qll;
const int MOD=1000000007;

ll extgcd(ll a,ll b,ll&x,ll&y)
{
   			 ll d=a;
   			 if(b)d=extgcd(b,a%b,y,x),y-=(a/b)*x;else x=1,y=0;
   			 return d;
}

ll mod_inverse(ll a,ll m)
{
   				  ll x,y;
   				  extgcd(a,m,x,y);
   				  return ((ll)(m+x%m)%m);
}

ll mod_power(ll x,ll n)
{
   				 ll res=1;
   				 while(n)
   				 {
				  		 if(n&1)res=res*x%MOD;
				  		 x=x*x%MOD;
				  		 n=n>>1;
				}
				return res;
}

int main()
{
 	string s;
 	ll k;
 	cin>>s>>k;
 	ll ans=0,p1=1;
 	
 	rep(i,s.size())
 	{
	 			   if(s[i]=='0'||s[i]=='5')ans=(ans+p1)%MOD;
	 			   p1*=2;
	 			   p1%=MOD;
	}
	
	cout<<ans*(mod_power(p1,k)-1+MOD)%MOD*mod_inverse(p1-1,MOD)%MOD;
	
    return 0;
}