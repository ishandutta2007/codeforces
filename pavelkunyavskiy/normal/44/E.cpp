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
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    string s;
    int k,a,b;
    cin>>k>>a>>b>>s;
    int n=s.size();
    if (k*a>n || k*b<n){
        printf("No solution\n");
        return 0;
    }
    vector<int> e;      
    for (int i=a-1;i<n && e.size()<k-1;i+=a)
        e.pb(i);
    if (e.back()!=n-1)
        e.pb(n-1);
    int ptr=int(e.size())-1;
    for (;ptr>0 && e[ptr]-e[ptr-1]>b;){
        e[ptr-1]=e[ptr]-b;
        ptr--;
    }
    
    ptr=0;
    
    for (int i=0;i<n;i++){
        printf("%c",s[i]);
        if (e[ptr]==i){
            ptr++;
            printf("\n");
        }
    }
    
    return 0;
}