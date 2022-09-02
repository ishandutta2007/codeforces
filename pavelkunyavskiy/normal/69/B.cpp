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

#define time botva452

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int time[1100];
int val[1100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m;
    cin>>n>>m;
    memset(time,-1,sizeof(time));
    memset(val,0,sizeof(val));
    for (int i=0;i<m;i++){
        int l,r,t,c;
        cin>>l>>r>>t>>c;
        --l,--r;
        for (int j=l;j<=r;j++){
            if (time[j] == -1 || time[j] > t){
                time[j] = t;
                val[j] = c;
            }
        }
    }
    int sum=0;
    for (int i=0;i<n;i++)
        sum+=val[i];
    cout << sum << endl;
    return 0;
}