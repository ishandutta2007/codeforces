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

int mat[1123][1123];
ll sum,v[1123];
int n,q;

int main(){
  int i,j,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&mat[i][j]);
    }
  }
  for(i=0;i<n;i++){
    sum+=mat[i][i];
  }

  scanf("%d",&q);
  int mode,val;
  while(q--){
    scanf("%d",&mode);
    if(mode==3){
      printf("%d",sum%2);
    }else{
      scanf("%d",&val);
      sum++;
    }
  }
  return 0;
}