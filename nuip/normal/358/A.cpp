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


int n,i,j,x[1000];

bool cross(int s,int k){
  int ls=min(x[s],x[s-1]),rs=max(x[s],x[s-1]),
  lk=min(x[k],x[k-1]),rk=max(x[k],x[k-1]);
/*  if((ls-lk)*(rs-rk)>0 && (lk-rs)*(rk-ls)<0){
        cout<<i<<","<<j<<endl;
    cout<<(ls-lk)*(rs-rk)<<"&"<<(lk-rs)*(rk-ls)<<endl;
 cout<<(ls-lk)<<"*"<<(rs-rk)<<"&"<<(lk-rs)<<"*"<<(rk-ls)<<endl;
  }*/
  return (ls>lk)==(rs>rk) && (lk>rs)!=(rk>ls)
    && (ls!=lk) &&(rs!=rk)&&(lk!=rs)&&(rk!=ls);
}

int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",x+i);
  }

  bool f=0;
  for(i=1;i<n;i++){
    for(j=1;j<n;j++){
      if(cross(i,j)){
        f=1;
      }
    }
  }

  cout<<(f?"yes":"no")<<endl;
  return 0;
}