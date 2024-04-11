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

int main(){
  int ngx[105],ngy[105];
  bool engx=0,engy=0;
  int i,j,n;
  char c[200];
  scanf("%d",&n);
  memset(ngx,-1,sizeof(ngx));
  memset(ngy,-1,sizeof(ngy));
  for(i=0;i<n;i++){
    scanf("%s",c);
    for(j=0;j<n;j++){
      if(c[j]=='.'){
        ngy[i]=j;
        ngx[j]=i;
      }
    }
  }
  for(i=0;i<n;i++){
    engx|=(-1==ngx[i]);
    engy|=(-1==ngy[i]);
  }

  if(engy){
    if(engx){
      printf("-1\n");
    }else{
      for(i=0;i<n;i++)
        printf("%d %d\n",ngx[i]+1,i+1);
    }
  }else{
    for(i=0;i<n;i++)
      printf("%d %d\n",i+1,ngy[i]+1);
  }
  return 0;
}