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


map < LL, int > mm;
LL cnt[200001], ar[200001];
LL pre[200001], val[200001], post[200011];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n){
        cin >> ar[i];
        mm[ar[i]] = 1;
    }
    int cc = 0;
    for(auto &v: mm){
        v.yy = ++cc;
        val[cc] = v.xx;
    }
    REP(i, n){
        cnt[ mm[ar[i]] ]++;
    }

    pre[0] = 1;
    for(int i = 1; i <= cc; i++) pre[i] = ((cnt[i] + 1) * pre[i-1]) % (mod-1);
    post[cc+1] = 1;
    for(int i = cc; i >= 1; i--) post[i] = ((cnt[i]+1) * post[i+1]) % (mod-1);

    LL res = 1;
    for(int i = 1; i <= cc; i++){
        LL p = 1, v = (pre[i-1] * post[i+1]) % (mod - 1);
        for(int j = 0; j <= cnt[i]; j++){
            res = (res * bigmod(p, v, mod)) % mod;
            p = (p * val[i]) % mod;
        }
    }

    cout << res << endl;
}