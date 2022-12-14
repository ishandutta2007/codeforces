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


LL seg[1000001];
void insert(int idx, int s, int e, int p, LL v){
    if(s == e){
        seg[idx] = (seg[idx] * v) % mod;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = (seg[idx * 2 + 1] * seg[idx * 2 + 2]) % mod;
}
LL query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        return (query(idx * 2 + 1, s, mid, st, mid) * query(idx * 2 + 2, mid + 1, e, mid + 1, ed)) % mod;
    }
}
vector < LL > prime, inv, inv1;
int isp[1000001], pos[1000001], init[1000001];
LL mul[200001], ar[200001], res[200001];
pair < pair < int, int >, int > pp[200001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i <= 1000000; i++){
        if(isp[i] == 0){
            prime.pb(i);
            inv.pb(modinverse((LL)i, mod));
            inv1.pb(modinverse((LL)(i-1), mod));
            init[i] = prime.size() - 1;
            for(int j = i * 2; j <= 1000000; j += i) isp[j] = 1;
        }
    }

    REP(i, 1000000) seg[i] = 1;
    int n; cin >> n;
    FOR(i, 1, n+1) {
        cin >> ar[i];
    }

    int q; cin >> q;
    REP(i, q){
        cin >> pp[i].xx.yy >> pp[i].xx.xx;
        pp[i].yy = i;
    }
    sort(pp, pp + q);

    int last = 0;
    mul[0] = 1;
    REP(i, q){
        for(int j = last + 1; j <= pp[i].xx.xx; j++){
            int v = ar[j];
            REP(k, prime.size()){
                if(prime[k]*prime[k] > v) break;
                if(v % prime[k] == 0){
                    if(pos[k] != 0) {
                        insert(0, 1, n, pos[k], ( prime[k]*inv1[k] )%mod);
                    }
                    pos[k] = j;
                    insert(0, 1, n, j, ( ( prime[k]-1 )*inv[k] )%mod );
                    while(v % prime[k] == 0) v /= prime[k];
                }
            }

            if(v > 1){
                v = init[v];
                if(pos[v] != 0) insert(0, 1, n, pos[v], ( prime[v] * inv1[v] )%mod);
                pos[v] = j;
                insert(0, 1, n, j, ( ( prime[v]-1 )*inv[v] )%mod );
            }
            mul[j] = (ar[j] * mul[j-1]) % mod;
        }
        last = pp[i].xx.xx;

        res[pp[i].yy] = (mul[pp[i].xx.xx] * modinverse( mul[ pp[i].xx.yy-1 ], mod) ) % mod;
        res[pp[i].yy] = (res[pp[i].yy] * query(0, 1, n, pp[i].xx.yy, pp[i].xx.xx)) % mod;
//        cout << pp[i].yy << " " << res[pp[i].yy] << " " << query(0, 1, n, pp[i].xx.yy, pp[i].xx.xx) << endl;
    }

    REP(i, q) cout << res[i] << endl;
}