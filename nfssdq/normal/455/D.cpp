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

int ar[321][100001];
deque < int > dq[321];
void rev(int l, int r){
    if((l/320) == (r/320)){
        int a = dq[l/320][r % 320];
        for(int i = r; i > l; i--) dq[l/320][i % 320] = dq[l/320][(i-1) % 320];
        dq[l/320][l%320] = a;
        return;
    }
    int a = dq[r/320][r%320];
    while(r % 320 != 0){
        dq[r/320][r%320] = dq[r/320][(r-1)%320];
        r--;
    }
    ar[r/320][a]--;
    dq[r/320].pop_front();
    for(int i = r; i > l; i -= 320){
        dq[i/320].push_front(dq[(i-1)/320].back());
        ar[i/320][dq[(i-1)/320].back()]++;
        ar[(i-1)/320][dq[(i-1)/320].back()]--;
        dq[(i-1)/320].pop_back();
    }
    dq[l/320].pb(a);
    ar[l/320][a]++;
    for(int i = 319; i > (l%320); i--){
        swap(dq[l/320][i], dq[l/320][i-1]);
    }
}
int query(int l, int r, int v){
    int ret = 0;
    while(l % 320 != 0 && l < r){
        if(dq[l/320][l%320] == v)ret++;
        l++;
    }
    while(r >= l && r % 320 != 319){
        if(dq[r/320][r%320] == v)ret++;
        r--;
    }
    for(int i = l; i < r; i += 320){
        ret += ar[i/320][v];
    }
    return ret;
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f,g,h = 0,x,y,z;
    cin >> a;
    REP(i, a){
        cin >> b;
        dq[i/320].pb(b);
        ar[i/320][b]++;
    }
    cin >> b;
    z = 0;
    REP(i, b){
        cin >> c >> d >> e;
        d = ((d + z - 1) % a) + 1; d--;
        e = ((e + z - 1) % a) + 1; e--;
        if(d > e) swap(d, e);
        if(c == 2){
            cin >> f;
            f = ((f + z - 1) % a) + 1;
            z = query(d, e, f);
            cout << z << endl;
        } else {
            rev(d, e);
        }
    }
}