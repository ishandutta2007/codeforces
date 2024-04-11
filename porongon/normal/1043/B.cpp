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

int n;
int a[1024];
int x[1024];
vi r;

bool can(int k){
  FORN(i,k)x[i]=a[i+1]-a[i];
  FORN(i,n)if(a[i+1]-a[i]!=x[i%k])return 0;
  return 1;
}

int main(){
  scanf("%d",&n);
  FOR(i,1,n+1)scanf("%d",a+i);
  FOR(i,1,n+1)if(can(i))r.push_back(i);
  printf("%d\n",SZ(r));
  FORN(i,SZ(r))printf("%d%c",r[i]," \n"[i==SZ(r)-1]);
  return 0;
}