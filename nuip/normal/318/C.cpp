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

ll x[2],m,temp,sum;

int main(){
  bool bl;
  sum=0;
  cin>>x[0]>>x[1]>>m;
  if(x[0]<x[1]){
    temp=x[0];
    x[0]=x[1];
    x[1]=temp;
  }
  if(x[0]>=m){
    cout<<sum<<endl;
    return 0;
  }
  if(x[1]<=0){
    if(x[0]<=0){
      cout<<"-1"<<endl;
      return 0;
    }
    sum=(-x[1])/x[0]+1;
    x[1]+=x[0]*sum;
  }
 // cout<<x[0]<<","<<x[1]<<endl;

  for(bl=0;1;bl^=1){
    if(x[bl]>=m){
      cout<<sum<<endl;
      break;
    }
    x[bl^1]+=x[bl];
    sum++;
  }
  return 0;
}