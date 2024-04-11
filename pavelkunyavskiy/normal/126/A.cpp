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

typedef long long ll;
typedef long double ld;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    ll t0,x1,x2,t1,t2;

    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    if (t1 == t0 && t2 == t0){
        cout << x1 <<" "<<x2 <<endl;
        return 0;
    }
    if (t1 == t0){
        cout << x1 <<" "<<0 << endl;
        return 0;
    }
    if (t2 == t0){
        cout << 0 <<" "<<x2 << endl;
        return 0;
    }

    ll bestp,bestq;
    bestp = 1LL<<60;
    bestq = 0;
    int best1,best2;

    best1 = best2 = -1;

    

    for (int i = 0; i <= x1; i++){
        ll y2 = (t0*1LL*i - t1 * 1LL *i)/(t2-t0);
        if (y2 * 1LL* (t2 - t0) < (t0*1LL*i - t1 * 1LL * i))
            y2++;

//      cerr << i <<" "<<y2 << endl;
        if (i == 0)
            y2 = x2;

        if (y2 > x2)
            continue;

        ll curp = (t1 * 1LL * i + t2 * 1LL * y2);
        ll curq = i + y2;

        if (curq == 0)
            continue;

        if (bestq == 0 || (bestp * curq > curp * bestq) || (bestp * curq == curp * bestq && bestq < curq)){
            bestp = curp;
            bestq = curq;
            best1 = i;
            best2 = y2;
        }
    }

    cout << best1 <<" "<<best2 << endl;

  return 0;
}