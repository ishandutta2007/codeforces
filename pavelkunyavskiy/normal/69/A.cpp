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

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int a,b,c;
    int a1,b1,c1;
    int n;
    cin>>n;
    a=b=c=0;
    for (int i=0;i<n;i++){
        cin>>a1>>b1>>c1;
        a+=a1;
        b+=b1;
        c+=c1;
    }   
    if (a==0 && b==0 && c==0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}