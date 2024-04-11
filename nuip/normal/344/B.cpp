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

int v[3],p[3],sum,vsum;
bool imp=0;

int main(){
  cin>>p[0]>>p[1]>>p[2];
  sum=p[0]+p[1]+p[2];
  imp|=(sum%2);
  for(int i=0;i<3;i++){
    imp|=(sum<2*p[i]);
    vsum+=v[i]=(sum-p[i]*2)/2;
  }
  if(imp || vsum==2*sum)
    cout<<"Impossible"<<endl;
  else
    cout<<v[2]<<" "<<v[0]<<" "<<v[1]<<endl;
  return 0;
}