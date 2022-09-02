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



bool used[1100000];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  
  int64 n,d,l,m;
  cin>>n>>d>>m>>l;

  int64 last=(n-1)*m+l;
  
	int64 coord=0;
	used[0]=true;
	for (;;){
		coord+=d;
		int coordm=coord%m;
		if (used[coordm] || coord>last)
			break;
		used[coordm]=true;
		if (coordm>l)
			{
				cout<<coord<<endl;
				return 0;
			}
	}
  
	int64 fall=last-(last%d)+d;
	for (;fall<=last;fall+=d);
	for (;fall-d>last;fall-=d);
	cout<<fall<<endl;
  
  return 0;
}