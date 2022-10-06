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
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool solve(){
  ll da[]={1,1,-1,-1},db[]={1,-1,1,-1};
  ll n,t,a,b,i,j,k,x,y,z,win;
  cin>>n>>t>>a>>b;
  win=n/3;
  if(n%3)return 0;
  rep(i,4){
    y=0,x=da[i]*a,z=db[i]*b;
   // cout<<x<<","<<y<<","<<z<<endl;
    ll tmp=min(x,z);
    if(tmp<0)
      x-=tmp,y-=tmp,z-=tmp;
   // cout<<x<<","<<y<<","<<z<<endl;
    tmp=t-x-y-z;
    if(tmp<0 || tmp%3)
      continue;
    //cout<<"!";
    tmp/=3;
    x+=tmp,y+=tmp,z+=tmp;
    tmp=max(x,max(y,z));
    if(tmp>win)
      continue;
    return 1;
  }
  return 0;
}

int main(){
  int i,j,k;
  int t,T;
  cin>>T;
  rep(t,T){
    cout<<(solve()?"yes":"no")<<endl;
  }
  return 0;
}