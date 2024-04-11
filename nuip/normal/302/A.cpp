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

long posi,nega,l,r;

int main(){
  long n,m;
  posi=0;
  nega=0;
  scanf("%ld %ld",&n,&m);
  long i,j,sum=0,temp;
  for(i=1;i<=n;i++){
    scanf("%ld",&temp);
    if(temp==1){
      posi++;
    }else{
      nega++;
    }
  }
  int re;
  for(i=0;i<m;i++){
    scanf("%ld %ld",&l,&r);
    if((r-l)%2==0){
      re=0;
    }else{
      long temp=(r-l+1)/2;
      if(posi>=temp && nega>=temp){
        re=1;
      }else{
        re=0;
      }
    }
    printf("%d\n",re);
  }
  return 0;
}