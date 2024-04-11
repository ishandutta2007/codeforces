#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

int64 gcd(int64 a,int64 b){
	if (b==0)
		return a;
	if (a==0)
		return b;
	return gcd(b,a%b);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int64 a,b,x,y;
  cin>>a>>b>>x>>y;
  int64 g=gcd(x,y);
  x/=g;
  y/=g;
  int64 k1=min(a/x,b/y);
  int64 x1=k1*x;
  int64 y1=k1*y;
	cout<<x1<<" "<<y1<<endl;
  return 0;
}