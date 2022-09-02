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

int p[4];

bool check(int x){
    sort(p,p+4);
    do {
//      cerr<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<p[3]<<endl;
        if (x == ((((x%p[0])%p[1])%p[2])%p[3]))
            return true;
    }
    while (next_permutation(p,p+4));
    return false;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>p[0]>>p[1]>>p[2]>>p[3];
    int a,b;
    cin>>a>>b;
    int cnt=0;
    for (int i=a;i<=b;i++)
        cnt+=check(i);
    cout << cnt << endl;
    return 0;
}