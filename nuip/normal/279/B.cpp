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

__int64 books,funMax;
vector<int> fun;

int main(){
  cin>>books>>funMax;

  __int64 st=0,end,cnt=0,cntm=0,maxc=0;
  int i,j,temp;
  bool flag=0;
  for(i=0;i<books;i++){
    cin>>temp;
    fun.push_back(temp);
    if((cntm+temp)>funMax)
      flag=1;
    if(flag)continue;
    cnt++;
    cntm+=temp;
  }
  maxc=end=cnt;
  __int64 remain=funMax-cntm;

  while(1){
   // cout<<"("<<st<<","<<end<<","<<remain<<"),";
    if(end>=books)
      break;
    if(fun.at(end)>funMax){
      end++;
      st=end;
      cnt=0;
      remain=funMax;
      if(end>=books)
        break;
    }else if(fun.at(end)<=remain){
      remain-=fun.at(end);
      end++;
      cnt++;
      maxc=max(maxc,cnt);
      if(end>=books)
        break;
    }else{
      cnt--;
      remain+=fun.at(st);
      st++;
    }
  }

  cout<<maxc<<endl;
  return 0;
}