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
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int d[2123][2123],n,pare[2123];
vector<int> edges[2123];

int push(int node,int p,int dist){
  if(d[node][p]!=dist)
    return 1;
  int cld=-1;
  rep(i,edges[p].size()){
    int tmp=edges[p][i];
    if(dist>d[node][tmp]){
      if(cld<0)
        cld=tmp;
      else
        return 1;
    }else if(dist+d[p][tmp]!=d[node][tmp])
      return 1;
  }
  if(cld<0){
    edges[p].pb(node);
    pare[node]=p;
  }else{
    return push(node,cld,dist-d[p][cld]);
  }
  return 0;
}

int check(int root,int cur,int p,int dist){
//  cout<<root<<","<<cur<<","<<p<<","<<dist<<endl;
  if(d[root][cur]!=dist)
    return 1;
  for(auto dst:edges[cur]){
    if(p==dst)continue;
    if(check(root,dst,cur,dist+d[cur][dst]))
      return 1;
  }
  return 0;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k,f=0;
  cin>>n;
  rep(i,n)rep(j,n)
    cin>>d[i][j];
  rep(i,n)rep(j,n){
    if((i==j) != (d[i][j]==0)){
      f=1;
    }
    if(d[i][j]!=d[j][i]){
      f=2;
    }
  }
  if(f){
    cout<<"NO"<<endl;
//    cout<<f;
    return 0;
  }
  vector<pii> v(n-1);
  rep(i,n-1)
    v[i]=pii(d[0][i+1],i+1);
  sort(all(v));
  rep(i,n-1){
 //   cout<<v[i].Y<<","<<v[i].X<<endl;
    if(push(v[i].Y,0,v[i].X)){
      cout<<"NO"<<endl;
   //   cout<<i<<"!";
      return 0;
    }
  }
  rep(i,n-1)
    edges[i+1].pb(pare[i+1]);
  rep(i,n)
    if(check(i,i,-1,0)){
      cout<<"NO"<<endl;
  //    cout<<i<<"?";
      return 0;
    }
  cout<<"YES"<<endl;
  return 0;
}