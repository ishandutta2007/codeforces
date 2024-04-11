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

void fun(int n,int x[112]){
  int i,j;
  for(i=0;i<n;i++)
    x[i]=1;
  if(n==2){
    x[0]=3;
    x[1]=4;
  }else if(n%2==0){
    x[n-1]=n/2-1;
  }else if(n!=1){
    x[n-2]=2;
    x[n-1]=n-n/2;
  }
  return;
}

int main(){
  int n,m,i,j,x[112],y[112];
  cin>>n>>m;
  fun(n,x);
  fun(m,y);
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      printf("%d%c",x[i]*y[j],(j==m-1?'\n':' '));
  return 0;
}