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

using namespace std;

int mapOut[3][3]={{1,1,1},
    {1,1,1},{1,1,1}};

void tgr(int x,int y,int num){
  if(x<0||2<x||y<0||2<y)
    return;
  mapOut[x][y]++;
  mapOut[x][y]%=2;
  return;
}
int main(){
  int temp;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>temp;
      if(temp%2==0)
        continue;
      tgr(j,i,temp);
      tgr(j+1,i,temp);
      tgr(j-1,i,temp);
      tgr(j,i+1,temp);
      tgr(j,i-1,temp);
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cout<<mapOut[j][i];
    }
    cout<<endl;
  }
  return 0;
}