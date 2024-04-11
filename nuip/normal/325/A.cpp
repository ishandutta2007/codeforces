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


int main(){
  int n,s,t,u,v,S,T,U,V,sumS=0;
  S=T=40000;
  U=V=0;
  scanf("%d",&n);
  while(n--){
    scanf("%d %d %d %d",&s,&t,&u,&v);
    sumS+=(u-s)*(v-t);
    S=min(S,s);
    T=min(T,t);
    U=max(U,u);
    V=max(V,v);
  }
  cout<<(U-S==V-T && (U-S)*(V-T)==sumS?"YES":"NO")<<endl;
  return 0;
}