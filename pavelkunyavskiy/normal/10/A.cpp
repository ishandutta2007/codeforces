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

int l[100];
int r[100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n,p1,p2,p3,t1,t2;
  cin>>n>>p1>>p2>>p3>>t1>>t2;
  for (int i=0;i<n;i++)
  	scanf("%d %d",&l[i],&r[i]);
 	int pt=0;
 	int st=0;
 	int ans=0;
  for (int i=l[0];i<r[n-1];i++){
  	if (i==l[pt])
  		st=0;
  	else if (i==r[pt])
  		pt++;
  	else if (i<l[pt])
  		st++;
  	if (st>=t1+t2)
  		ans+=p3;
  	else if (st>=t1)
  		ans+=p2;
  	else
  		ans+=p1;  	
  }
  cout<<ans<<endl;
  return 0;
}