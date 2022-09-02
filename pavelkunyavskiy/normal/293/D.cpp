//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;

pair<int,int> p[110000];
pair<int,int> p2[110000];
int n;

int gety(const pair<int,int>& p1,const pair<int,int>& p2,int x,int up){
    if (p1.first == p2.first){
        if (!up) return max(p1.second,p2.second);
        return min(p1.second,p2.second);
    }   
    ll num = (p2.second - p1.second) * 1LL * (x - p1.first);
    ll den = (p2.first - p1.first);
                                                    
    ll mod = ((num % den) + den) % den;
//    eprintf("!!! " LLD" "LLD" "LLD" ",num,den,mod);
    num -= mod;                           
    if (!up && mod > 0) num += den;
//    eprintf("   -> "LLD"\n",num / den);
    return num / den + p1.second;
}

ll vp(ll x1,ll y1,ll x2,ll y2){
    return x1 * y2 - x2 * y1;
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
        scanf("%d %d",&p[i].first,&p[i].second);


    ld ans = 0;

    for (int it = 0; it < 2; it++){
        rotate(p,min_element(p,p+n),p+n);
        for (int j = 0; j < n; j++)
            p2[j] = p[j];
        reverse(p2+1,p2+n);

        int ptr1,ptr2;
        ptr1 = ptr2 = 0;

        int maxx = max_element(p,p+n)->first;

        ld cntall,expx,expx2;
        cntall = expx = expx2 = 0;

        if (vp(p[1].first - p[0].first,p[1].second - p[0].second,p2[1].first - p2[0].first,p2[1].second - p2[0].second) < 0){
            for (int j = 0; j < n; j++)
                swap(p[j],p2[j]);
        }

        while (p[ptr1].first == p[ptr1+1].first) ptr1++;
        while (p2[ptr2].first == p2[ptr2+1].first) ptr2++;

        for (int x = p[0].first; x <= maxx; x++){
            while (p[ptr1+1].first < x) ptr1++;
            while (p2[ptr2+1].first < x) ptr2++;

            int y1 = gety(p[ptr1],p[ptr1+1],x,0);
            int y2 = gety(p2[ptr2],p2[ptr2+1],x,1);

            int cnt = y2 - y1 + 1;

/*          eprintf("%d %d %d %d [(%d,%d) -- (%d,%d)] [(%d,%d) -- (%d,%d)]\n",x,cnt,y1,y2,
                                                                                p[ptr1].first,p[ptr1].second,p[ptr1+1].first,p[ptr1+1].second,
                                                                                p2[ptr2].first,p2[ptr2].second,p2[ptr2+1].first,p2[ptr2+1].second);*/

            cntall += cnt;
            expx += x * 1LL * cnt;
            expx2 += x * 1LL * x * 1LL * cnt;
        }

//      eprintf("%lf %lf %lf\n",(double)expx,(double)expx2,(double)cntall);


                                    
        expx /= cntall;
        expx2 /= cntall;


//      eprintf("%lf %lf\n",(double)expx,(double)expx2);

        ans += 2 * (expx2 - expx*expx) * cntall / (cntall - 1);


        for (int j = 0; j < n; j++)
            swap(p[j].first,p[j].second);
//        break;
    }

    printf("%.8lf\n",(double)ans/2);
      
    TIMESTAMP(end);
    return 0;
}