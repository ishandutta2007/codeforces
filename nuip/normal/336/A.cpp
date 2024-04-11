#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >


using namespace std;
typedef __int64 ll;



int main(){
  long ax,ay,bx,by,x,y,sum;
  int aa[2][2][4]={{{-1,0,0,-1},{0,-1,1,0}},{{-1,0,0,1},{0,1,1,0}}};
  cin>>x>>y;
  sum=abs(x)+abs(y);
  for(int i=0;i<4;i++)
    printf("%ld%c",sum*aa[y>0][x>0][i],(i==3?'\n':' '));
  return 0;
}