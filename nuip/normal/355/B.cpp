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

ll c1,c2,c3,c4,a[1123],b[1123],n,m;

int main(){
  ll i,j;
  cin>>c1>>c2>>c3>>c4;
  cin>>n>>m;
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  for(i=0;i<m;i++){
    cin>>b[i];
  }


  ll minC=c4,minT=c3,minB=c3,sum;
  for(i=sum=0;i<n;i++){
    sum+=min(c1*a[i],c2);
  }
  minB=min(sum,minB);
  for(i=sum=0;i<m;i++){
    sum+=min(c1*b[i],c2);
  }
  minT=min(minT,sum);

  cout<<min(minT+minB , minC)<<endl;
  return 0;
}