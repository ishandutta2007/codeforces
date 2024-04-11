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
typedef unsigned int uint;

uint x[210000];
int n;

bool check(uint D){
    int id=0;
    uint p;
    for (int i=0;i<3;i++){
        p=x[id]+2*D;
        if (p>=x[n-1])
            id=n;
        else
            id=upper_bound(x,x+n,p)-x;
        if (id >= n) return true;
    }
    return false;
}

void print(uint D){
    cout.precision(6);
    cout<<fixed<<(((ld)D)/2)<<endl;
    int id=0;
    uint p;
    for (int i=0;i<3;i++){
        if (id >= n){
            cout.precision(6);  
            cout<<fixed<<2*(1e+8)<<" \n"[i==2];         
        }
        else{       
            p=x[id]+2*D;
            if (p>=x[n-1])
                id=n;
            else
                id=upper_bound(x,x+n,p)-x;
            cout.precision(6);
            cout<<fixed<<((ld)(p-D))/2<<" \n"[i==2];
        }
    }
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%u",&x[i]);
        x[i]*=2;
    }
    sort(x,x+n);
    int l=-1;
    int r=(x[n-1]+100)/2;
    for (;r-l>1;){
        int mid=l+(r-l)/2;
        if (check(mid))
            r=mid;
        else
            l=mid;
    }
    print(r);
    return 0;
}