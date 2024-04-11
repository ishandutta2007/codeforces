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

const ld eps=1e-09;

int x[3];
int y[3];


bool check(int f,int s,int t){
	int64 scal=(x[s]-x[f])*1ll*(x[t]-x[f])+(y[s]-y[f])*1ll*(y[t]-y[f]);
	return scal==0 && (x[s]!=x[f] || y[s]!=y[f]) && (x[t]!=x[f] || y[t]!=y[f]);	
}

bool check(){
	return check(0,1,2) || check(1,0,2) || check(2,1,0);
}

const char* ans[3]={"NEITHER","ALMOST","RIGHT"};

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  
  for (int i=0;i<3;i++)
  	scanf("%d %d",&x[i],&y[i]);
  	
  if (check()){
  	cout<<ans[2]<<endl;
  	return 0;
  }
  
  for (int i=0;i<3;i++){
  	for (int dx=-1;dx<=1;dx+=2)
  		{
  			x[i]+=dx;
  			if (check())
  			{
  				cout<<ans[1]<<endl;
  				return 0;
  			}
  			x[i]-=dx;
  		}
  		
  	 for (int dx=-1;dx<=1;dx+=2)
  		{
  			y[i]+=dx;
  			if (check())
  			{
  				cout<<ans[1]<<endl;
  				return 0;
  			}
  			y[i]-=dx;
  		}
  }
  
  cout<<ans[0]<<endl;
  
  return 0;
}