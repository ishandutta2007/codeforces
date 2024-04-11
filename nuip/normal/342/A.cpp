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

int nums[8],n124,n126,n136,n;

int main(){
  scanf("%d",&n);
  int i,j,tmp;
  bool ng=0;

  for(i=0;i<n;i++){
    scanf("%d",&tmp);
    nums[tmp]++;
  }
  
  if(nums[7]){
    ng=1;
  }else{
    if(nums[1]!=n/3)
      ng=1;
    if(nums[3]){
      if(nums[1]>=nums[3]){
        nums[1]-=nums[3];
      }else{
        ng=1;
      }
      if(nums[6]>=nums[3]){
        nums[6]-=nums[3];
      }else{
        ng=1;
      }
      n136=nums[3];
      nums[3]=0;
    }
    if(nums[4]){
      if(nums[1]>=nums[4]){
        nums[1]-=nums[4];
      }else{
        ng=1;
      }
      if(nums[2]>=nums[4]){
        nums[2]-=nums[4];
      }else{
        ng=1;
      }
      n124=nums[4];
      nums[4]=0;
    }
    if(nums[2]){
      if(nums[1]==nums[2] && nums[2]==nums[6]){
        n126=nums[2];
        nums[1]=nums[2]=nums[6]=0;
      }else{
        ng=1;
      }
    }
    for(i=1;i<=7;i++){
      if(nums[i]!=0){
        ng=1;
        //cout<<"!"<<endl;
      }
    }
  }
  if(ng){
    cout<<-1<<endl;
  }else{
    for(i=0;i<n124;i++)
      cout<<"1 2 4"<<endl;
    for(i=0;i<n126;i++)
      cout<<"1 2 6"<<endl;
    for(i=0;i<n136;i++)
      cout<<"1 3 6"<<endl;
  }   
  return 0;
}