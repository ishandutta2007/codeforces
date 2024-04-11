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


char dir[100005],cdx,cdy;
short dirx[260],diry[260];
ll dx,dy,len;


int main(){
/*  dirx[N]=dirx[S]=0;
  dirx[E]=1;
  dirx[W]=-1;
  diry[W]=diry[E]=0;
  diry[N]=1;
  diry[S]=-1;
 */ ll a,b,c,d;
  scanf("%I64d %I64d %I64d %I64d %I64d"
        ,&len,&a,&b,&c,&d);
  dx=c-a;
  dy=d-b;
  if(dx>=0){
    cdx='E';
  }else{
    cdx='W';
    dx*=-1;
  }
  if(dy>=0){
    cdy='N';
  }else{
    cdy='S';
    dy*=-1;
  }
  //cout<<cdx<<","<<cdy<<endl;
  int i;
  scanf("%s",dir);
  for(i=0;i<len;i++){
    if(dx==0 && dy==0){
      printf("%d\n",i);
      return 0;
    }
    if(dir[i]==cdx){
    //cout<<dir[i]<<","<<dx<<","<<dy;
      dx--;
    }
    if(dir[i]==cdy){
      dy--;
    }
    if(dx<=0 && dy<=0){
      printf("%d\n",i+1);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}