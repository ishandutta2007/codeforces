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

int a[112345],ans[112345];
set<int> s;

int main(){
  int n,m,p;
  int i,j;

  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    scanf("%d",a+i);
  }
  for(i=n-1;i>=0;i--){
    s.insert(a[i]);
    ans[i]=s.size();
  }
  for(i=0;i<m;i++){
    scanf("%d",&p);
    printf("%d\n",ans[p-1]);
  }
  return 0;
}