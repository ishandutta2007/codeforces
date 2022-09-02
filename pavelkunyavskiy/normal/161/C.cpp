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

int ans = 0;

int getmaxcpos(int l1,int r1){
    if (l1 == r1 && !(l1 & 1))
        return l1;
    if (!(l1 & 1))
        l1++;
    if (!(r1 & 1))
        r1--;
    return (getmaxcpos(l1/2,r1/2)-l1/2)*2+l1;        
}


int getmaxc(int l1,int r1){
    if (l1 == r1 && !(l1 & 1))
        return 0;
    if (!(l1 & 1))
        l1++;
    if (!(r1 & 1))
        r1--;
    return getmaxc(l1/2,r1/2)+1;        
}



void norm(int& l1,int& r1){
    int mc1 = getmaxc(l1,r1);

    for (int i = 30; i > mc1; i--)
        if (l1 >= (1<<i)){
            l1 -= (1<<i);
            r1 -= (1<<i);
        }
}


void solve(int l1,int r1,int l2,int r2){
    if (l1 > r1 || l2 > r2)
        return;
    if (l1 <= l2 && r2 <= r1){
        ans = max(ans,r2-l2+1);
        return;
    }
    if (l2 <= l1 && r1 <= r2){
        ans = max(ans,r1-l1+1);
        return;
    }
    if (l1 == 0 && l2 == 0){
        ans = max(ans,min(r1,r2)+1);
        return;
    }
    if (((r1+1)&(r1+2)) == 0 && ((r2+1)&(r2+2)) == 0){
        ans = max(ans,min(r1-l1,r2-l2)+1);
        return;
    }

    norm(l1,r1);
    norm(l2,r2);
//    cerr << "!!!"<<l1 <<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    
    int mc1 = getmaxc(l1,r1);
    int mc2 = getmaxc(l2,r2);

//    cerr << mc1 <<" "<<mc2 << endl;


                                            
    if (mc1 < mc2){
        solve(l2,r2,l1,r1);
        return;
    }


    solve(l1,getmaxcpos(l1,r1)-1,l2,r2);
    solve(getmaxcpos(l1,r1)+1,r1,l2,r2);

    if (mc1 == mc2){
    
        int pos1 = getmaxcpos(l1,r1);
        int pos2 = getmaxcpos(l2,r2);

        assert(pos1 == pos2);
        ans = max(ans,min(r1,r2) - max(l1,l2)+1);
    }
}

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    --l1,--r1,--l2,--r2;
    solve(l1,r1,l2,r2);
    cout << ans << endl;
    return 0;
}