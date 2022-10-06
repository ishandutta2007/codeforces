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
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int p[112345];
set<int> st,AB[2];
int n,a,b,ab[2],f;

int stcount(int m){
  if(st.count(m)){
    return !(AB[0].count(m)||AB[1].count(m));
  }else
    return 0;
}

int find(int i,int type){
  f=1;
  if(stcount(ab[type]-i)){
    AB[type].insert(i);
    AB[type].insert(ab[type]-i);
 //   st.erase(i);
 //   st.erase(ab[type]-i);
    if(stcount(ab[1-type]-ab[type]+i))
      return find(ab[1-type]-ab[type]+i,type);
    return 0;
  }else{
    return 1;
  }
}

int main(){
  int i,j,k;
  cin>>n>>a>>b;
  ab[0]=a;
  ab[1]=b;
  rep(i,n){
    cin>>p[i];
    st.insert(p[i]);
  }
  rep(i,n){
    if(!st.count(a-p[i]) && !st.count(b-p[i])){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if(a==b){
    cout<<"YES"<<endl;
    rep(i,n)cout<<"0 ";cout<<endl;
    return 0;
  }
//  while(!st.empty()){
//    f=0;
    for(auto pp:st){
//      if(f)break;
      if(!stcount(pp))continue;
      if(!stcount(b-pp)){
        if(find(pp,0)){
          cout<<"NO"<<endl;
          return 0;
        }
//      if(f)break;
      }else if(!stcount(a-pp)){
        if(find(pp,1)){
          cout<<"NO"<<endl;
          return 0;
        }
 //     if(f)break;
      }
 //   }
  }/*
  for(auto bb:st){
    if(A.count(bb))continue;
    if(!st.count(b-bb)){
      cout<<"NO"<<endl;
      return 0;
    }
  }*/
  rep(i,n){
    if(!AB[0].count(p[i])&&!AB[1].count(p[i])){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  rep(i,n){
    cout<<AB[1].count(p[i])<<" ";
  }cout<<endl;
  return 0;
}