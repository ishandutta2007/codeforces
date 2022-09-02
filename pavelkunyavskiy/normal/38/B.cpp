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
#define x first
#define y second

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

typedef pair<int,int> pii;

bool correct(pii l,pii k1,pii k2){
    if (l==k1 || l==k2 || k1==k2)
        return false;
    if (k1.x==l.x || k1.y==l.y)
        return false;
    if (k2.x==l.x || k2.y==l.y)
        return false;
    for (int i=-2;i<=2;i++)
        for (int j=-2;j<=2;j++)
            if (abs(i)+abs(j)==3){
                if (mp(k1.x+i,k1.y+j)==l || mp(k1.x+i,k1.y+j)==k2)
                    return false;
                if (mp(k2.x+i,k2.y+j)==l || mp(k2.x+i,k2.y+j)==k1)
                    return false;
            }
    return true;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    pii l,k1,k2;
    char c;int a;
    scanf(" %c %d ",&c,&a);
    l=mp(int(c-'a'),a-1);
    scanf(" %c %d ",&c,&a);
    k1=mp(int(c-'a'),a-1);  
    int cnt=0;
    for (k2.first=0;k2.first<8;++k2.first)
        for (k2.second=0;k2.second<8;++k2.second)
            if (correct(l,k1,k2))
                cnt++;
    cout<<cnt<<endl;                
    return 0;
}