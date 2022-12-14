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
#define linf       (1ll<<62)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M) {
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b) {if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M) {return bigmod(a,M-2,M);}


LL ar[2][200001];
LL val[305][3];
deque < pair < LL, LL > >dq;

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = -linf,f,g,h = 1,x = 1,y,z = 1;
    cin >> a >> b >> c;
    REP(i, b)cin >> val[i][0] >> val[i][1] >> val[i][2];
    for(int i = 1; i <= a; i++){
        ar[0][i] = val[b - 1][1] - abs(val[b - 1][0] - i);
    }
    LL mx = -linf;
    for(int i = b - 2; i >= 0; i--){
        x = - c * (val[i + 1][2] - val[i][2]);
        y = - x;
        while(!dq.empty())dq.pop_front();
        for(int j = 1; j <= a; j++){
            x++; y++;
            e = max(1ll, x);
            f = min(a, y);
            g = -linf; h = 0;
            if(j == 1){
                z = f;
                if(f == y)z--;
                for(int k = e; k <= z; k++){
                    while(1){
                        if(dq.size() == 0)break;
                        pair < LL, LL > pp = dq.back();
                        if(pp.xx >= ar[0][k])break;
                        dq.pop_back();
                    }
                    dq.push_back(mp(ar[0][k], k));
                }
            }
            if(f == y){
                while(1){
                    if(dq.size() == 0)break;
                    pair < LL, LL > pp = dq.back();
                    if(pp.xx >= ar[0][f])break;
                    dq.pop_back();
                }
                dq.push_back(mp(ar[0][f], f));
            }
            while(dq.size() > 0){
                pair < LL, LL > pp = dq.front();
                if(pp.yy < e)dq.pop_front();
                else break;
            }
            ar[1][j] = val[i][1] - abs(val[i][0] - j) + (dq.front()).xx;
        }
        for(int j = 1; j <= a; j++)ar[0][j] = ar[1][j];
    }
    e = -linf;
    for(int i = 1; i <= a; i++)e = max(e, ar[0][i]);
    cout << e << endl;
}