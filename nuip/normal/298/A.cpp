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


char foot[1005];
int len,changed,cLoc[10];

int cntChange(){
  int i,sum=0,j=0;
  for(i=1;i<len;i++){
    if(foot[i-1]!=foot[i]){
      cLoc[sum]=i;
      sum++;
    }
  }
  return sum;
}

int main(){
  int i;
  scanf("%d",&len);
  scanf("%s",foot);

  changed=cntChange();
  if(changed==2){
    if(foot[cLoc[0]]=='R'){
      printf("%d %d\n",cLoc[0]+1,cLoc[1]+1);
    }else{
      printf("%d %d\n",cLoc[1]-1+1,cLoc[0]-1+1);
    }
  }else if(changed==3){
    if(foot[cLoc[0]]=='R'){
      printf("%d %d\n",cLoc[0]+1,cLoc[1]-1+1);
    }else{
    }
  }
  return 0;
}