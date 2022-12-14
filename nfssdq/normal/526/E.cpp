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

LL ar[2000001], sum[2000001], nxt[2000001], cnt[2000001], last[2000001];
void query(int n, LL v){
    int p = 1;
    FOR(i, 1, 2*n+1){
        while(p <= 2*n && sum[p] - sum[i-1] <= v) p++;
        nxt[i] = p-1;
    }
    for(int i = n; i >= 1; i--){
        if(nxt[i] >= n){
            cnt[i] = 1;
            last[i] = nxt[i] - n;
            continue;
        }
        last[i] = last[ nxt[i]+1 ];
        cnt[i] = cnt[nxt[i]+1] + 1;
    }
    LL res = n;
    FOR(i, 1, n+1){
        if(last[i] >= i-1) res = min(res, cnt[i]);
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, q; cin >> n >> q;
    FOR(i, 1, n+1){
        cin >> ar[i];
        ar[i+n] = ar[i];
    }
    FOR(i, 1, 2*n+1) sum[i] += sum[i-1] + ar[i];
    while(q--){
        LL v; cin >> v;
        query(n, v);
    }
}