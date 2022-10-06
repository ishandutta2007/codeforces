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
typedef __int64 ll;

bool langlang[101][101];
bool used[101];
int muchi=0;
int empN,langN;

void check(int num){
  used[num]=0;
  for(int i=1;i<=langN;i++){
    if(i==num)continue;
    if(langlang[i][num]){
      langlang[i][num]=0;
      langlang[num][i]=0;
      check(i);
    }
  }
  return;
}

int main(){
  memset(langlang,0,sizeof(langlang));
  memset(used,0,sizeof(used));
  int i,j;

  cin>>empN>>langN;
  for(i=0;i<empN;i++){
    int temp,tnum;
    vector<int> tlang;
    cin>>temp;
    if(temp==0){
      muchi++;
      continue;
    }
    for(j=0;j<temp;j++){
      cin>>tnum;
      used[tnum]=1;
      tlang.push_back(tnum);
    }
    for(j=0;j<temp;j++){
      for(int k=j+1;k<temp;k++){
        langlang[tlang.at(k)][tlang.at(j)]=1;
        langlang[tlang.at(j)][tlang.at(k)]=1;
      }
    }
  }
  
  int grp=0;
  for(i=1;i<=langN;i++){
    if(used[i]){
      grp++;
      check(i);
    }
  }
  if(grp>0)
    grp-=1;
  cout<<muchi+grp<<endl;
  return 0;
}