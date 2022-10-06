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

int main(){
  int i,j,k,n,m;
  cin>>n>>m>>k;
  cout<<m*(m-1)/2<<endl;
  for(i=1;i<m;i++){
    for(j=i+1;j<=m;j++){
      if(k==0)printf("%d %d\n",i,j);
      else printf("%d %d\n",j,i);
    }
  }
  return 0;
}