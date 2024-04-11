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
#define abs(a) (((a)>=0)?(a):(-(a)))
using namespace std;


int64 gcd(int64 a,int64 b){
	if (a==0)
		return b;
	if (b==0)
		return a;
	return gcd(b,a%b);
}

int64 gcd(int64 a,int64 b,int64 c){
	return gcd(gcd(a,b),c);
}

void gcdex(int64 a,int64 b,int64 &x,int64 &y)
{
	if (a==0){
		x=0;
		y=1;
		return;
	}
	int64 x1,y1;
	gcdex(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return;
}

int main()
{
  /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif*/
  int64 a,b,c;
  cin>>a>>b>>c;
  if (c==0){
  	printf("0 0\n");
  	return 0;  	
  }
  int64 g=gcd(abs(a),abs(b));
  if (abs(c)%g!=0){
  	printf("-1\n");
  	return 0;
  }
  a/=g;
  b/=g;
  c/=g;
  int64 x, y;
  gcdex(abs(a),abs(b),x,y);
  if (a<0)
  	x=-x;
  if (b<0)
  	y=-y;
  x*=-c;
  y*=-c;
  cout<<x<<" "<<y<<endl;
  return 0;
}