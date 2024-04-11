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

int dels[2500];
int cnt;

void getdels(int n){
    for (int i=1;i*i<=n;i++){
        if (n%i==0){
            dels[cnt++]=i;
            if (i!=n/i)
                dels[cnt++]=n/i;        
        }
    }
    sort(dels,dels+cnt);
}

int t[2500];

void gen(int n){
    if (n==0){
        printf("%d\n",dels[n]);
        return;
    }
    printf("%d ",dels[n]);
    int best=0;
    for (int j=0;j<n;j++)
        if (dels[n]%dels[j]==0 && t[best] < t[j])
            best=j;
    gen(best);          
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    cin>>n;
    getdels(n);
    for (int i=0;i<cnt;i++){
        t[i]=1;
        for (int j=0;j<i;j++)
            if (dels[i]%dels[j]==0)
                t[i]=max(t[i],t[j]+1);      
    }
    gen(cnt-1);
    return 0;
}