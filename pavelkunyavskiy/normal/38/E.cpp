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

int64 t[4000][2];
int c[4000];
int x[4000];
int por[4000];

bool cmp(const int& a,const int& b){
    return x[a]<x[b];
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d %d",&x[i],&c[i]);
        por[i]=i;
    }
    sort(por,por+n,cmp);
    t[0][1]=c[por[0]];
    t[0][0]=(1LL<<60LL);
    //cerr<<t[0]<<endl;
    for (int i=1;i<n;i++){
        int v=por[i];
        t[i][1]=min(t[i-1][0],t[i-1][1])+c[v];      
        t[i][0]=(1LL<<60LL);
        int64 sum=0;            
        for (int j=i-1;j>=0;j--){
            sum+=(x[por[j+1]]-x[por[j]])*1LL*(i-j);
            t[i][0]=min(t[i][0],t[j][1]+sum);
        }
//      cerr<<t[i]<<endl;           
    }
    cout<<min(t[n-1][0],t[n-1][1])<<endl;
    return 0;
}