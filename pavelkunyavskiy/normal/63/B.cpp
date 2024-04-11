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

int a[110];
int n;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        int v;
        cin>>v;
        a[v]++;
    }
    int cnt=0;
    for (;;){
        if (a[k]==n)
            break;
        ++cnt;
        for (int i=k-1;i>=0;--i){   
            if (a[i]){
                a[i+1]++;
                a[i]--;
            }           
        }   
    }
    
    cout<<cnt<<endl;
    
  
    return 0;
}