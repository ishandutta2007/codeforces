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
  ll i,j,dig=1,w,m,k,cost=0,len=0;
  cin>>w>>m>>k;
  w/=k;
  i=dig=1;
  while(dig<=m){
    dig*=10;
    i++;
  }//cout<<i<<","<<m-dig<<endl;
  while(cost+(dig-m)*(i-1)<=w){
    cost+=(dig-m)*(i-1);
    len+=dig-m;
    m=dig;
    dig*=10;
    i++;
  }//cout<<w<<","<<cost<<endl;
  len+=(w-cost)/(i-1);
  cout<<len<<endl;
  return 0;
}