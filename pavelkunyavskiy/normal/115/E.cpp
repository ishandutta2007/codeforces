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
typedef long double ld;

const int MAXN = 210000;

int l[MAXN];
int r[MAXN];

struct comp{
    bool operator()(int a,int b){
        if (r[a] != r[b])
            return r[a] < r[b];
        return a < b;
    }
};

set<int,comp> s;

ll sum;
int have[MAXN];
int need[MAXN];


vector<pair<int,int> > v;


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n,m;
  scanf("%d %d",&n,&m);
  for (int i = 0; i < n; i++)
    scanf("%d",&need[i]);
  for (int i = 0; i < m; i++){
    scanf("%d %d %d",&l[i],&r[i],&have[i]);
    --l[i],--r[i];
    v.pb(mp(l[i],i));
    sum += have[i];
  }

  sort(v.begin(),v.end());
  int ptr = 0;

  for (int i = 0; i < n; i++){
      while (ptr < m && v[ptr].first <= i)
        s.insert(v[ptr].second),ptr++;

/*        cerr << need[0] <<" "<<need[1] <<" "<<need[2] << endl;
      cerr << have[0] <<" "<<have[1] << endl;
      cerr << endl;*/

      while (!s.empty() && need[i]){
        int v = *s.begin();
        s.erase(s.begin());
        if (r[v] < i)
            continue;
        if (have[v] >= need[i]){
            have[v] -= need[i];
            sum -= need[i];
            need[i] = 0;
            s.insert(v);
        }
        else {
            sum -= have[v];
            need[i] -= have[v];
            have[v] = 0;
        }
      }
  }

  cout << sum << endl;  

  return 0;
}