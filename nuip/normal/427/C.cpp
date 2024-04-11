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

int cost[112345],num[112345],numn[112345],used[112345],cnt;
vector<int> path[112345],rev[112345],hoge;

void mark(int p){
  int i,j;
  num[p]=1;
 // cout<<p<<"(";
  for(i=0;i<path[p].size();i++){
    if(num[path[p][i]]==0)mark(path[p][i]);
  }//cout<<")"<<p;
  num[p]=++cnt;
  numn[cnt]=p;
  return;
}

void solve(int p){
  int i,j;
  used[p]=1;
  hoge.pb(p);//cout<<p<<"<";
  for(i=0;i<rev[p].size();i++){
    if(used[rev[p][i]])continue;
    solve(rev[p][i]);
  }//cout<<">"<<p;
  return;
}
    

int main(){
  int i,m,n,j,k;
  ll minv=0,re=1,MOD=1e9+7;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",cost+i);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    path[a-1].pb(b-1);
    rev[b-1].pb(a-1);
  }
  fill(num,num+112345,0);
  for(i=0;i<n;i++)
    if(num[i]==0)mark(i);
 // for(i=0;i<n;i++)
//    cout<<i<<":"<<num[i]<<endl;
  fill(used,used+112345,0);
  //cnt=0;
   for(i=n;i>0;i--){
//    for(j=0;j<n;j++)
//      cout<<used[j];
//    cout<<endl;
    if(used[numn[i]]==0){
      hoge.clear();
      solve(numn[i]);
  //    for(j=0;j<hoge.size();j++)
   //     cout<<hoge[j]<<",";
    //  cout<<endl;
      ll mnv=1ll<<60,mincnt=1;
      for(j=0;j<hoge.size();j++){
        int tmp=cost[hoge[j]];
        if(mnv==tmp)
          mincnt++;
        if(mnv>tmp){
          mincnt=1;
          mnv=tmp;
        }
      }
      minv+=mnv;
      re=(re*mincnt)%MOD;
//      cout<<minv<<" "<<re<<endl;
    }
  }
  cout<<minv<<" "<<re<<endl;
  return 0;
}