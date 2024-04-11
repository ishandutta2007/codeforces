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

queue<pair<int,int> > path[112345];
int used[112345];
vector<int> ans;

int solve(int p){
  used[p]=1;
  int re=0,tmp;
  while(!path[p].empty()){
    if(!used[path[p].front().X])
      if(tmp=solve(path[p].front().X)){
        re+=tmp;
      }else if(path[p].front().Y==2){
        re++;
        ans.pb(path[p].front().X);
      }
    path[p].pop();
  }
  
  return re;
}

int main(){
  int i,j,n,k;

  scanf("%d",&n);
  int x,y,t;
  for(i=1;i<n;i++){
    scanf("%d %d %d",&x,&y,&t);
    path[x].push(make_pair(y,t));
    path[y].push(make_pair(x,t));
  }
  solve(1);
  printf("%d\n",ans.size());
  for(i=0;i<ans.size();i++){
    printf("%d ",ans[i]);
  }
  return 0;
}