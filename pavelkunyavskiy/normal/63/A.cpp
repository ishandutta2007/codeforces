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

typedef long long int64;
typedef long double ld;

pair<string,string> a[110];

bool cmp(const pair<string,string>& a,const pair<string,string>& b){
    if (b.second=="rat")
        return false;
    if (a.second=="rat")
        return true;
    if (b.second=="woman" || b.second=="child")
        return false;
    if (a.second=="woman" || a.second=="child")
        return true;
    if (b.second=="man")
        return false;
    if (a.second=="man")
        return true;
    return false;
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    stable_sort(a,a+n,cmp);
    for (int i=0;i<n;i++)
        cout<<a[i].first<<endl;
    return 0;
}