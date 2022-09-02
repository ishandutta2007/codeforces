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

const int MAXN=1100;

int ans[MAXN];
int a[MAXN];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=n-1;i>=0;--i){
        int j=0;
        for (;a[i];++j)
            if (ans[j] >= i+k)
                --a[i];
        for (int l=n-i-1;l>j;l--)
            ans[l]=ans[l-1];
        ans[j]=i;

    }
    for (int i=0;i<n;i++)
        cout<<ans[i]+1<<" ";
    cout<<endl;
    return 0;
}