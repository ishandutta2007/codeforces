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
  int n,a[312];
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",a+i);
  }
  for(i=0;i<300;i++){
    for(j=0;j<n-1;j++){
      if(a[j]>0){
        a[j]--;
        putchar('P');
      }
      putchar('R');
    }
    for(j=n-1;j>0;j--){
      if(a[j]>0){
        a[j]--;
        putchar('P');
      }
      if(j!=0)putchar('L');
    }
  }
  return 0;
}