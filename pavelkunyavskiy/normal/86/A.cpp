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


int64 best = 0;

int len(int64 x){
    int cnt=0;
    for (;x;x/=10)
        cnt++;
    return cnt;
}

int64 nines(int cnt){
    int64 x = 0;
    for (int i=0;i<cnt;i++)
        x = x*10 + 9;
    return x;
}

int64 l,r;

void tryw(int x){
    if (x < l || x>r)
        return;
    best = max(best,x*(nines(len(x))-x));
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>l>>r;
    tryw(l);
    tryw(r);
    for (int i=1;i<=10;i++){
        int64 x = nines(i);
        for (int j=-10;j<=10;j++)
            tryw(x+j);
        x/=2;
        for (int j=-10;j<=10;j++)
            tryw(x+j);
    }
    cout << best << endl;
    return 0;
}