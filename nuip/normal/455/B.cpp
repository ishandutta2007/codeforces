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

int node[112345][26],trsize;

int dfs(int cur,int b,int c,string str){
//  cout<<"["<<str<<endl;
  int i,j,k;
  bool f=1;
  rep(i,26){
    if(node[cur][i]){
      f=0;
      if(1-b==dfs(node[cur][i],c,b,str+char(i+'a'))){
//            cout<<"]"<<str<<endl;
        return b;
      }
    }
  }
//    cout<<"]"<<str<<endl;
  return f?0:1-b;
}

int main(){
  ll i,j,k,n,t;
  string str,re[]={"First","Second"};
  cin>>n>>t;
  rep(i,n){
    cin>>str;
    int cur=0;
    rep(j,str.size()){
      if(node[cur][str[j]-'a']==0)
        node[cur][str[j]-'a']=++trsize;
      cur=node[cur][str[j]-'a'];
    }
  }
  ll ww=dfs(0,1,1,""),l2=dfs(0,0,0,""),
  wl=dfs(0,1,0,""),lw=dfs(0,0,1,"");
//  cout<<ww<<","<<wl<<endl<<lw<<","<<ll<<endl;
  if(ww){
    if(l2){
      cout<<re[1-t%2]<<endl;
    }else{
      cout<<re[0]<<endl;
    }
  }else{
    cout<<re[1]<<endl;
  }
  return 0;
}