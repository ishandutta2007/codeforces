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

int v[1000];

int main(){
  int n,i,j,in,nn;
  cin>>n;
  nn=n;
  while(nn--){
    cin>>in;
    for(i=0;i<in;i++){
      v[i]++;
    }
  }
  for(i=n;i>0;i--){
    for(j=0;v[j]>=i;j++);
    
    cout<<j<<" ";
  }
  return 0;
}