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

void out(int x){    
    cout << x << endl;
    exit(0);
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m,a,b;
    cin>>m>>n>>a>>b;
    if (n == 1)
        out(1);
    int l1 = (a-1)/n;
    int l2 = (b-1)/n;
    if (b == m)
        b = (l2+1)*n;
    if (l1 == l2)
        out(1);
    if (l1+1 == l2)
        out(2 - (a%n ==1 && b%n == 0));
    cerr << a%n <<" "<<b%n << endl;
    out(3 - (a%n == 1) - (b%n == 0) - (a%n == (b+1)%n && b%n != 0));    
    return 0;
}