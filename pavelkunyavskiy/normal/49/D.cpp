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

int n;
int a[1100];

int solve(int start){
    int cnt=0;
    for (int i=0;i<n;i++){
        if (a[i]!=start) cnt++;
        start^=1;
    }
    return cnt;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n;
    for (int i=0;i<n;i++){
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    cout<<min(solve(0),solve(1))<<endl;
    return 0;
}