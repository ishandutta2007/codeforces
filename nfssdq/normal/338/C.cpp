/********************************************************************************\
   |--\        ---       /\        |-----------| -----       /-------|           |
   |   \        |       /  \       |               |        /                    |
   |    \       |      /    \      |               |       |                     |
   |     \      |     /      \     |               |        \---\                |
   |      \     |    / ------ \    |-------|       |             \---\           |
   |       \    |   /          \   |               |                  |          |
   |        \   |  /            \  |               |                  /          |
  ---        \------            ------           -----     |---------/           |
                                                                                 |
                          _                                                      |
  **copyrighted by nfssdq(R) :) (:                                               |
                          ^                                                      |
    codeforces = nfssdq                                                          |
    topcoder = nafis007                                                          |
    uva = nfssdq                                                                 |
    spoj = nfssdq                                                                |
    usaco = nfssdq1                                                              |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                           |
    IIT,Jahangirnagar University(41)                                             |
    Sorry for badly written code.  :(                                            |
                                                                                 |
*********************************************************************************/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M){
    LL md=M;
    if( e==0 )return 1;
    if( e%2==0 ){
        LL t = bigmod( p, e/2, M );
        return (T)( ( t*t ) % md );
    }
    LL bm = bigmod( p, e-1, M );
    bm = ( bm * (LL)p )%md;
    return (T)bm;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

pair < LL, LL > pp[10];
LL ar[10];
LL orig[10];
LL isp[1000001];
vector < LL > prime;
LL res = mod;
int tot;
void bctrack(int cur){
    if(cur == tot){
        LL s = 0;
        LL cnt = 0;
        REP(i, tot){
            if(orig[i] == 1 && pp[i].yy == 0)continue;
            if(pp[i].yy <= 1) s++;
            else s += pp[i].yy + 1;
            if(pp[i].yy >= 1)cnt ++;
            //cout << pp[i].xx << " " << pp[i].yy << endl;
        }
        //cout << "-------------------------" << endl;
        if(cnt > 1) s++;
        res = min(res, s);
        return;
    }
    bctrack(cur + 1);
    REP(i, tot){
        if(i == cur)continue;
        if(pp[i].xx % ar[cur] == 0){
            LL a = ar[cur];
            LL c = pp[cur].yy;
            pp[i].xx /= a;
            pp[cur].yy = 0;
            bctrack(cur + 1);
            pp[cur].yy = c;
            pp[i].xx *= a;
        }
    }
}
main(){
    LL a,b,c,d,e,f,g,x,y,z;
    for(int i = 2; i <= 1000000; i++){
        if(isp[i] == 0){
            prime.pb(i);
            for(int j = i * 2; j <= 1000000; j += i)isp[j] = 1;
        }
    }
    cin >> a;
    REP(i, a){
        cin >> pp[i].xx;
        ar[i] = pp[i].xx;
        pp[i].yy = 0;
        b = pp[i].xx;
        REP(j, prime.size()){
            while(b % prime[j] == 0){
                pp[i].yy ++;
                b /= prime[j];
            }
        }
        if(b > 1)pp[i].yy ++;
    }
    sort(pp, pp + a);
    sort(ar, ar + a);
    REP(i, a)orig[i] = pp[i].yy;
    tot = a;
    bctrack(0);
    cout << res << endl;
}