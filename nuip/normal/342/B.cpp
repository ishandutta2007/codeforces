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

int spies,m,s,f,v;
char ch;
vector<long> t,l,r;

int main(){
  scanf("%d %d %d %d",&spies,&m,&s,&f);
  long i,j,tmp1,tmp2,tmp3;

  for(i=0;i<m;i++){
    scanf("%ld %ld %ld",&tmp1,&tmp2,&tmp3);
    t.pb(tmp1);
    l.pb(tmp2);
    r.pb(tmp3);
  }
  int pos;
  bool ng;
  v=(s<f)?1:-1;
  ch=(s<f)?'R':'L';
  for(i=1,j=0,pos=s;pos!=f;i++){
    ng=0;
    if(t[j]==i){
      if( (l[j] <= pos && pos <= r[j])
       || (l[j] <= pos+v && pos+v <= r[j]) ){
        ng=1;
      }
      if(t.size()!=j-1)j++;
    }
    if(ng){
      putchar('X');
    }else{
      putchar(ch);
      pos+=v;
    }
  }
  return 0;
}