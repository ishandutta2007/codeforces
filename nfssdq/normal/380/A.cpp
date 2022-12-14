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
#define pii        pair<int,int>
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

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

pair < LL, LL > pp[100001];
LL len[100001];

LL go(LL c, LL p){
    if(pp[c].yy == -1)return pp[c].xx;
    p -= len[c - 1];
    LL a = p % pp[c].xx;
    if(a == 0)a = pp[c].xx;
    LL d = lower_bound(len + 1, len + c + 1, a) - len;
    return go(d, a);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b = 0,c,d,e,f,g,h = 1,x,y,z;
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> b >> c;
        len[i] = len[i - 1];
        if(b == 1) {
            pp[i] = mp(c, -1ll);
            len[i]++;
        }
        else {
            cin >> d;
            pp[i] = mp(c, d);
            len[i] += c * d;
        }
    }
    cin >> b;
    c = 0;
    REP(i, b){
        cin >> d;
        e = lower_bound(len + 1, len + a + 1, d) - len;
        //cout << e << endl;
        cout << go(e, d) << " ";
    }
    cout << endl;

}

/*
5
1 1
1 2
2 2 3
2 3 2
1 3
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/
//1 2 1 2 1 2 1 2 1 2 1 1 2 1 3