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

int n,m;
int f[60];

int main(){
  int i,j;

  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d",f+i);
  }
  sort(f,f+m);

  int minDif=10000,tmp;
  for(i=0;i+n<=m;i++){
    tmp=*max_element(f+i,f+i+n)-*min_element(f+i,f+i+n);
    if(tmp<minDif)minDif=tmp;
  }

  cout<<minDif<<endl;
  return 0;
}