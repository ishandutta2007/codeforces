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

int n,m,l,r,x,win[312345];
vector<int> ad[312345],rem[312345];
set<int> beat;
set<int>::iterator it,ite;

int main(){
  scanf("%d %d",&n,&m);
  int i,j;

  for(i=0;i<m;i++){
    scanf("%d %d %d",&l,&r,&x);
    win[i]=x;
    ad[l].pb(i);
    rem[r+1].pb(i);
  }

  int ans;
  for(i=1;i<=n;i++){
    for(j=0;j<ad[i].size();j++){
      beat.insert(ad[i].at(j));
    }
    for(j=0;j<rem[i].size();j++){
      beat.erase(rem[i].at(j));
    }
    for(it=beat.begin();it!=beat.end();it++){
      if(win[(*it)]!=i)
        break;
    }
    if(it==beat.end())
      ans=0;
    else
      ans=(win[*it]);

    printf("%d%c",ans,n==i?'\n':' ');
  }
  
  return 0;
}