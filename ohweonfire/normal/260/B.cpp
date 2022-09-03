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

const int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

map<string,int>f;
string s;


int main()
{
 	int y,m,d,j;
 	string t="",x;
 	cin>>s;
 	for(int i=0;i+10<=(int)s.size();i++)
 	{
	 		x=s.substr(i,10);
	 		if(sscanf((x+"*1").c_str(),"%2d-%2d-%4d*%d",&d,&m,&y,&j)!=4)continue;
	 		if(y<2013||y>2015)continue;
	 		if(m<1||m>12)continue;
	 		if(d<1||d>day[m])continue;
	 		if(f[t]<++f[x])t=x;
	}
	
	cout<<t;
	
    return 0;
}