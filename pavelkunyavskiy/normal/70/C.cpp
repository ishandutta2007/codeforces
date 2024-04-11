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

map<pair<int,int>,int> xr;
map<pair<int,int>,int> rx;

int64 cur = 0;

int gcd(int a,int b){
    if (!a || !b) return a+b;
    return gcd(b,a%b);
}

int rev(int a){
    int b = 0;
    for (;a;a/=10)
        b=b*10+a%10;
    return b;
}



void add(int i){
    int tmp=rev(i);
    int g=gcd(i,tmp);
    pair<int,int> val=mp(i/g,tmp/g);
    if (xr.find(val) == xr.end())
        xr[val] = 1;
    else
        xr[val] ++;
    if (rx.find(val) != rx.end())
        cur += rx[val];
}

void del(int i){
    int tmp=rev(i);
    int g=gcd(i,tmp);
    pair<int,int> val=mp(tmp/g,i/g);
    rx[val] --;
    if (xr.find(val) != xr.end())
        cur -= xr[val];
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    
    int maxx,maxy,w;
    cin>>maxx>>maxy>>w;
    
    for (int i=1;i<=maxy;i++){
        int tmp=rev(i);
        int g=gcd(i,tmp);
        pair<int,int> val=mp(tmp/g,i/g);
        if (rx.find(val) == rx.end())
            rx[val] = 1;
        else
            rx[val] ++;
    }
    
    int bestn = -1;
    int bestm = -1;
    int ptr = maxy;
    
    for (int i=1;i<=maxx;i++){
        add(i);
        for (;cur >= w;){
            if (bestn == -1 || (i * 1LL * ptr < bestn* 1LL *bestm)){
                bestn=i;
                bestm=ptr;
            }
            del(ptr);
            --ptr;
        }
    }

    cout << bestn;
    if (bestn != -1)
        cout << " "<<bestm;
    cout << endl;
    
  
    return 0;
}