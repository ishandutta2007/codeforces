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

const int MAXN = 110000;

int next[MAXN][20];
int a[MAXN];
int n;


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  	scanf("%d",&n);
    for (int i = 0; i < n; i++)
       scanf("%d",&a[i]);

    vector<int> v;
    set<int> s;

    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < (int)v.size(); j++)
        	v[j] |= a[i];
        v.pb(a[i]);                 
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        s.insert(v.begin(),v.end());
    }

    cout << s.size() << endl;
      
    return 0;
}