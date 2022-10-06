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

int color[112345],n,m;

int main(){
  int i,j,tmp[4],f;

  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    f=0;
    for(j=1;j<=3;j++){
      scanf("%d",tmp+j);
      if(color[tmp[j]])
        f=j;
    }
    int c=1;
    for(j=1;j<=3;j++){
      if(f)if(c==color[tmp[f]]){
        c++;
      }
      if(j==f)
        continue;
      color[tmp[j]]=c;
      c++;
    }
  }
  for(i=1;i<=n;i++)
    printf("%d%c",color[i],(i==n)?'\n':' ');
  return 0;
}