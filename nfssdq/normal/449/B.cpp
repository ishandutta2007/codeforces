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
#define linf       (1ll<<60)-1
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

vector < LL > vc[100001], vt[100001];
priority_queue <
    pair < LL, LL >,
    vector < pair < LL, LL > >,
    greater < pair < LL, LL > >
> pq;
LL ar[100001], pre[100001];
pair < LL, LL > pp[100001];
LL tmp[100001], pos[100001];
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f,g,h = 0,x,y,z;
    cin >> a >> b >> c;
    REP(i, b){
        cin >> d >> e >> f;
        vc[d].pb(e);
        vc[e].pb(d);
        vt[d].pb(f);
        vt[e].pb(f);
    }
    setinf(tmp);
    REP(i, c){
        cin >> d >> e;
        vc[1].pb(d);
        vt[1].pb(-e);
        if(e < tmp[d]){
            pos[d] = i;
            tmp[d] = e;
        }
        pp[i] = mp(d, e);
    }
    setinf(ar);
    ar[1] = 0;
    pre[1] = 1;
    pq.push(mp(0, 1));
    while(!pq.empty()){
        pair < LL, LL > p = pq.top();
        pq.pop();
        if(ar[p.yy] < p.xx) continue;
        REP(i, vc[p.yy].size()){
            d = vc[p.yy][i];
            e = vt[p.yy][i];
            if(e > 0){
                if(ar[d] > e + p.xx){
                    ar[d] = e + p.xx;
                    pq.push(mp(ar[d], d));
                    pre[d] = p.yy;
                } else if(ar[d] == e + p.xx) pre[d] = p.yy;
            } else {
                e *= -1;
                if(ar[d] > e + p.xx){
                    ar[d] = e + p.xx;
                    pq.push(mp(ar[d], d));
                    pre[d] = -p.yy;
                }
            }
        }
    }
    f = 0;
    REP(i, c){
        if(pre[pp[i].xx] > 0 || pos[pp[i].xx] != i)f++;
    }
    cout << f << endl;
}