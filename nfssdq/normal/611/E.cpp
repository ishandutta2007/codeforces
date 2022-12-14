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
#define PI         acos(-1.0)
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

LL ar[200001], vv[3], cnt[3];
int fl[200001];
int go(int m, int n){
    set0(fl);
    int cc = m;
    for(int i = n-1; i >= 0; i--){
        if(ar[i] <= vv[2] && cc > 0){
            cc--;
            fl[i] = 1;
        }
    }

    cc = m;
    for(int i = n-1; i >= 0; i--){
        if(fl[i] == 0 && ar[i] <= vv[0]+vv[1] && cc > 0 && ar[i] > vv[1]){
            cc--;
            fl[i] = 1;
        }
    }

    int c1 = cc+cnt[1];
    for(int i = n-1; i >= 0; i--){
        if(fl[i] == 0 && ar[i] <= vv[1] && c1 > 0){
            c1--;
            fl[i] = 1;
        }
    }

    c1 = cc + cnt[0];
    for(int i = n-1; i >= 0; i--){
        if(fl[i] == 0 && ar[i] <= vv[0] && c1 > 0){
            c1--;
            fl[i] = 1;
        }
    }

    REP(i, n){
        if(ar[i] <= max(vv[2], vv[0]+vv[1]) && fl[i] == 0) return 0;
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n; cin >> n;
    REP(i, 3) cin >> vv[i];
    REP(i, n) cin >> ar[i];
    sort(vv, vv + 3);

    sort(ar, ar + n);
    int add = 0;
    for(int i = n-1; i >= 0; i--){
        if(ar[i] > vv[0]+vv[1]+vv[2]){
            cout << -1 << endl;
            return 0;
        }
        if(ar[i] > vv[1]+vv[2]){
            add++;
            continue;
        }
        if(ar[i] > vv[2]+vv[0]){
            cnt[0]++;
            add++;
            continue;
        }
        if(ar[i] > max(vv[2], vv[0]+vv[1])){
            cnt[1]++;
            add++;
            continue;
        }

    }


    int lo = 0, hi = n, mid = (lo + hi) / 2;
    while(lo < mid){
        if(go(mid, n)) hi = mid;
        else lo = mid + 1;
        mid = (lo + hi) / 2;
    }
    if(go(mid, n) == 0) mid++;

    cout << mid+add << endl;
}