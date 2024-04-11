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
  ll p,x,i,sum=1,re=0;
  cin>>p;
  for(x=1;x<p;x++){
    for(i=1;i<=p;i++){
      sum*=x;
      sum%=p;
      if(sum==1)
        break;
    }
    if(i==p-1){
      re++;
    }
  }
  cout<<re<<endl;
  return 0;
}