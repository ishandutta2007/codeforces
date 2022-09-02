#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <queue>
#include <memory.h>
#include <stack>
#include <deque>

#define mp make_pair
#define pb push_back

#define taskname "B"
                   
#ifdef __WIN32
  #define LLD "%I64d"
#else
  #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

const int coef[10]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

struct gon{
  string name;
  vector<int> a;
  gon(){
    name="";
    a.resize(100);
    for (int i=0;i<100;i++)
      a[i]=0;
  }
  gon(string Name){
    name=Name;
    a.resize(100);
    for (int i=0;i<100;i++)
      a[i]=0;         
  }

};

//map<string,int> names;
int cnt;
gon spis[100000];

int getname(string s){
  for (int i=0;i<cnt;i++)
    if (spis[i].name==s)
      return i;
  spis[cnt]=gon(s);
  ++cnt;
  return cnt-1;
}


void readone(){
  int n;  
  scanf("%d\n",&n);
  string s;
  for (int i=0;i<n;i++){
    getline(cin,s);
    int tmp=getname(s);
    assert(spis[tmp].name==s);
    spis[tmp].a[i]++;
  }
}

int64 calc(const gon& a){   
  int64 tmp=0;
  for (int i=0;i<10;i++)
    tmp+=a.a[i]*1LL*coef[i];
  return tmp;
}

bool cmp1(const gon& a,const gon& b){
  int64 sc1=calc(a);
  int64 sc2=calc(b);
  if (sc1!=sc2)
    return sc1>sc2;
  for (int i=0;;i++)
    if (a.a[i]!=b.a[i])
      return a.a[i]>b.a[i];
  //assert(false);
  return a.name<b.name;
}


bool cmp2(const gon& a,const gon& b){
  if (a.a[0]!=b.a[0])
    return a.a[0]>b.a[0];
  int64 sc1=calc(a);
  int64 sc2=calc(b);
  if (sc1!=sc2)
    return sc1>sc2;
  for (int i=0;;i++)
    if (a.a[i]!=b.a[i])
      return a.a[i]>b.a[i];
  //assert(false);
  return a.name<b.name;
}


int main(){
#ifdef LOCAL
  freopen(taskname".in","r",stdin);
  freopen(taskname".out","w",stdout);
#endif
  int t;
  scanf("%d\n",&t);
  cnt=0;
  for (int i=0;i<t;i++)
    readone();
  gon best=spis[0];
  for (int i=1;i<cnt;i++)
    if (cmp1(spis[i],best))
      best=spis[i];
  cout<<best.name<<endl;
  best=spis[0];
  for (int i=1;i<cnt;i++)
    if (cmp2(spis[i],best))
      best=spis[i];
  assert(cnt>0);
  cout<<best.name<<endl;
  return 0;
}