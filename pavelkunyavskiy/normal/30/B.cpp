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

const int din[12]={31,28,31,30,31,30,31,31,30,31,30,31};

bool correct(int d,int m,int y){
    if (d>31 || m>12 || y>99)
        return false;
    int dc=din[m-1];
    if (y%4==0 && m==2)
        dc++;
    if (d>dc)
        return false;
    return true;
}

bool good(int db,int mb,int yb,int df,int mf,int yf){
    yb+=18;
    if (yb>yf)
        return false;
    if (yb<yf)
        return true;
    if (mb>mf)
        return false;
    if (mb<mf)
        return true;
    if (db>df)
        return false;
    return true;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int db,mb,yb,df,mf,yf;
    scanf("%d.%d.%d",&df,&mf,&yf);
    scanf("%d.%d.%d",&db,&mb,&yb);
    if (correct(db,mb,yb) && good(db,mb,yb,df,mf,yf)){
            printf("YES\n");
            return 0;
        }
    if (correct(db,yb,mb) && good(db,yb,mb,df,mf,yf)){
            printf("YES\n");
            return 0;
        }
    if (correct(mb,db,yb) && good(mb,db,yb,df,mf,yf)){
            printf("YES\n");
            return 0;
        }
    if (correct(mb,yb,db) && good(mb,yb,db,df,mf,yf)){
            printf("YES\n");
            return 0;
        }
    if (correct(yb,db,mb) && good(yb,db,mb,df,mf,yf)){
            printf("YES\n");
            return 0;
        }
    if (correct(yb,mb,db) && good(yb,mb,db,df,mf,yf)){
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
  return 0;
}