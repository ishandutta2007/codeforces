/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int ar[222], tmp[222], on[222];
pair < int, int > pp[222];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    REP(i, a){
        cin >> ar[i];
        pp[i].xx = ar[i];
        pp[i].yy = i;
    }
    sort(pp, pp + a);
    e = -inf;
    for(int i = 0; i < a; i++){
        for(int j = i; j < a; j++){
            set0(on);
            d = 0;g = 0; h = b;
            for(int k = i; k <= j; k++){
                on[k] = 1;
                tmp[d++] = ar[k];
                g += ar[k];
            }
            sort(tmp, tmp + d);
            f = a - 1;
            for(int k = 0; k < d; k++){
                while(f >= 0 && on[pp[f].yy] == 1){
                    f--;
                }
                if(f < 0 || h == 0 || pp[f].xx < tmp[k]) continue;
                on[pp[f].yy] = 1;
                g += pp[f].xx;
                g -= tmp[k];
                h--;
            }
            e = max(e, g);
        }
    }

    cout << e << endl;

}