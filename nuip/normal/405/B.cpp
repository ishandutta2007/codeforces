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
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

int l[3123],r[3123],n;
string in;

int main(){
  int sum,i,j;
  cin>>n>>in;
  sum=1000000;
  for(i=0;i<n;i++,sum++){
    if(in[i]=='R'){
      sum=0;
    }
    if(in[i]=='L')
      sum=1000000;
    r[i]=sum;
  }
  sum=1000000;
  for(i=n-1;i>=0;i--,sum++){
    if(in[i]=='L')
      sum=0;
    if(in[i]=='R')
      sum=1000000;
    l[i]=sum;
  }
  int re=0;
  for(i=0;i<n;i++){
    if(l[i]+r[i]>=2000000){
      re++;
    }else if(l[i]==r[i]){
      re++;
    }
  }
  cout<<re<<endl;
  return 0;
}