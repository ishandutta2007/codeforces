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

char a[8][8];

bool check_h(int h){
	for (int i=0;i<8;i++)
		if (a[h][i]=='W')
			return false;
	return true;
}

bool check_w(int w){
	for (int i=0;i<8;i++)
		if (a[i][w]=='W')
			return false;
	return true;
}

int main()
{
 /* #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif*/
  for (int i=0;i<8;i++)
  	for (int j=0;j<8;j++){
  		cin>>a[i][j];
  	}
  int kolw=0,kolh=0;
  for (int i=0;i<8;i++)
  {
  	if (check_h(i))
  		kolh++;
  	if (check_w(i))
  		kolw++;
  }
  if (kolh==8 && kolw==8)
  	cout<<8<<endl;
  else
  	cout<<kolh+kolw<<endl;  
  return 0;
}