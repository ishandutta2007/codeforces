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

ll sum,tim[100003];

int main(){
  sum=0;
  tim[0]=0;
  ll i,j,n,m,c,t;
  scanf("%I64d %I64d",&n,&m);
  for(i=1;i<=n;i++){
    scanf("%I64d %I64d",&c,&t);
    tim[i]=tim[i-1]+c*t;
    //cout<<tim[i]<<" ";
  }
  for(i=0;i<m;i++){
    scanf("%I64d",&t);
    ll l=0,r=n,temp;
    while(r-l>1){
      //cout<<"|"<<l<<","<<r;
      temp=(l+r)/2;
      if(t<=tim[temp]){
        r=temp;
      }else{
        l=temp;
      }
    }
    printf("%I64d\n",r);
  }
  return 0;
}