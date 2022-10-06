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
  int n,tmp,pre=0,sum=0,i,j;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&tmp);
    if(pre!=tmp)sum++;
    pre=tmp;
  }
  cout<<sum<<endl;
  return 0;
}