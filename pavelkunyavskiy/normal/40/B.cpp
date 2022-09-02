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

int f(int n,int m,int x){
    n-=2*(x-1);
    m-=2*(x-1);
    if (n<=0 || m<=0)
        return 0;
    else{
        int ans=n*(m/2);
        if (m%2)
            ans+=n/2+n%2;
        return ans;
    }   
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m,x;
    cin>>n>>m>>x;
    cout<<f(n,m,x)-f(n,m,x+1)<<endl;
    
    return 0;
}