#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;


int n,m;
vi a,b;

int main(){
  scanf("%d%d",&n,&m);
  FORN(i,n){
    int x;
    scanf("%d",&x);
    a.push_back(x);
  }
  FORN(i,m){
    int x1,x2,y;
    scanf("%d%d%d",&x1,&x2,&y);
    if(x1>1)continue;
    b.push_back(x2);
  }
  a.push_back(1000000000);
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int j=0,r=1<<30;
  FORN(i,SZ(a)){
    // cual es el primero que no saco
    while(j<SZ(b)&&b[j]<a[i])j++;
    r=min(r,i+SZ(b)-j);
  }
  printf("%d\n",r);
  return 0;
}