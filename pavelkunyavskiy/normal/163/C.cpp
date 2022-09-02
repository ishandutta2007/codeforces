#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef double ld;

vector<pair<ld,int> > evs;

int n;
ld l,v1,v2;

int a[110000];

ld ans[110000];

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  cin >> n >> l >> v1 >> v2;

  for (int i = 0; i < n; i++)
    scanf("%d",&a[i]);

  ld to = l * v2 / (v1+v2);

  int cnt = 0;


  for (int i = 0; i < n; i++){
    if (a[i] < to){
        evs.pb(mp((to-a[i]),-1)),cnt++;
        evs.pb(mp(2*l-a[i],1));
    }
    else {
        evs.pb(mp(2*l-a[i],1));
        evs.pb(mp(2*l+to-a[i],-1));
    }
  }
     
  evs.pb(mp(0.0,cnt));
  evs.pb(mp(2*l,0));

//  for (int i = 0; i < (int)evs.size(); i++)
//    cerr << evs[i].first <<" "<<evs[i].second << endl;;

  sort(evs.begin(),evs.end());

  int bal = 0;

  for (int i = 0; i < (int)evs.size(); i++){
      if (i)
         ans[bal] += evs[i].first - evs[i-1].first;
      bal += evs[i].second;        
  }

  for (int i = 0; i <= n; i++)
    printf("%.12lf\n",ans[i]/(2*l));

  return 0;
}