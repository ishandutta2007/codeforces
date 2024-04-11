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

int gcd(int a,int b){
	if (b==0)
		return a;
	return gcd(b,a%b);
}

int sum(int n,int sis){
	int res=0;
	for (;n;n/=sis)
		res+=n%sis;
	return res;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int a;
  cin>>a;
  int s=0;
  for (int i=2;i<a;i++)
  	s+=sum(a,i);
  int tmp=gcd(s,a-2);
  int zn=a-2;
  zn/=tmp;
  s/=tmp;
  printf("%d/%d\n",s,zn);
  return 0;
}