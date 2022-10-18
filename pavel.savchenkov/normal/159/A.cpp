//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#define pb push_back
#define i64 long long
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);

using namespace std;

string name[2][1100];
int t[1100];
int n,d;
vector < pair <string,string> > res;

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d%d\n",&n,&d);
  forn(i,n)
  {
    cin >> name[0][i]; cin >> name[1][i]; scanf("%d",&t[i]);
  }
  
  forn(i,n)
    foran(j,i+1,n)
        if (name[0][i] == name[1][j] && name[1][i] == name[0][j] && t[j] - t[i] > 0 && t[j] - t[i] <= d)
            res.pb( make_pair(name[0][i],name[1][i]) );

  forn(i,(int)res.size()) if (res[i].first > res[i].second) swap(res[i].first,res[i].second);
  sort(res.begin(),res.end());
  res.resize( unique(res.begin(),res.end()) - res.begin() );
  
  printf("%d\n",(int)res.size());
  
  forn(i,(int)res.size())
    printf("%s %s\n",res[i].first.c_str(),res[i].second.c_str());     
  return 0;
}