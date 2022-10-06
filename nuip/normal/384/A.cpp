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

int main(){
  int n,i,j,sum=0;
  cin>>n;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      sum+=((i+j)%2==0);
    }
  }
  printf("%d\n",sum);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      sum+=(i+j)%2;
      printf("%c",(((i+j)%2)?'.':'C'));
    }printf("\n");
  }
  return 0;
}