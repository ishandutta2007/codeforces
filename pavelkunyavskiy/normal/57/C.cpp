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

const int mod=1000000007;

int pow(int x,int p){
    if (p==1) return x;
    if (p&1)
        return (pow(x,p-1)*1LL*x)%mod;      
    int tmp=pow(x,p>>1);
    return (tmp*1LL*tmp)%mod;
}

int c(int n){
    int ans=1;
    for (int i=n+1;i<2*n;i++)
        ans=(ans*1LL*i)%mod;
    for (int i=1;i<n;i++)
        ans=(ans*1LL*pow(i,mod-2))%mod;
    return ans;     
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    cin>>n;
    int tmp=c(n);
    tmp=(tmp*2)%mod;
    tmp=(tmp+mod-n)%mod;
    cout<<tmp<<endl;
    return 0;
}