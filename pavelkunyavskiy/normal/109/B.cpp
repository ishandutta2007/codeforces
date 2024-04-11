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

typedef unsigned long long int64;
typedef long double ld;


int64 all;
int64 good;
int64 l1,r1,l2,r2;


vector<int> luck;


void genluck(int64 cur){
    if (cur > 1e9)
        return;

    if (cur) luck.pb(cur);
    genluck(cur*10+4);
    genluck(cur*10+7);   
}



int64 getlen(int64 l,int64 r,int64 l1,int64 r1){
    l = max(l,l1);
    r = min(r,r1);
    if (r >= l)
        return r-l+1;
    return 0;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    genluck(0);
    sort(luck.begin(),luck.end());

  /*  for (int i = 0; i < 10; i++)
        cerr << luck[i] << " ";
    cerr << endl;*/

    int k;
    cin>>l1>>r1>>l2>>r2>>k;

    luck.pb(int(1e9 + 100));


    for (int it = 0; it < 2; it++){

        for (int i = 0; i+k < luck.size();i++){
            int64 temp = getlen((i?luck[i-1]+1:0),luck[i],l1,r1);
            int64 temp2 = getlen(luck[i+k-1],luck[i+k]-1,l2,r2);

            good += temp*temp2;


            if (it == 1 && k == 1 && temp*temp2 > 0)
                --good;
        }

        swap(l1,l2);
        swap(r1,r2);
    }
        


    all = (r1-l1+1)*(r2-l2+1);

    cout.precision(15);

    cout << fixed << ld(good)/ld(all) << endl;
    return 0;
}