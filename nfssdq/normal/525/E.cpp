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

unordered_map < LL, LL > mm[26];
LL ar[26], fact[20], tmp[26];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, K, s; cin >> n >> K >> s;
    fact[1] = 1;
    for(LL i = 2; i <= 19; i++) fact[i] = (fact[i - 1] * i);
    REP(i, n){
        cin >> ar[i];
    }
    int m1 = n/2, m2 = n - m1;

    LL res = 0;
    REP(i, 1<<m1){
        int cnt = 0;
        REP(j, m1){
            if(i & 1<<j) tmp[cnt++] = ar[j];
        }
        if(cnt == 0) continue;
        REP(j, 1<<cnt){
            int fl = 0;
            LL sum = 0;
            REP(k, cnt){
                if((j & 1<<k) && tmp[k] > 19) {
                    fl = 1;
                    break;
                }
                if(j & 1<<k) sum += fact[tmp[k]];
                else sum += tmp[k];
            }
            if(fl || sum > s || __builtin_popcount(j) > K) continue;
            mm[__builtin_popcount(j)][ sum ]++;
            if(sum == s) res++;
        }
    }

    REP(i, 1<<m2){
        int cnt = 0;
        REP(j, m2){
            if(i & 1<<j) tmp[cnt++] = ar[m1 + j];
        }
        if(cnt == 0) continue;
        REP(j, 1<<cnt){
            int fl = 0;
            LL sum = 0;
            REP(k, cnt){
                if((j & 1<<k) && tmp[k] > 19) {
                    fl = 1;
                    break;
                }
                if(j & 1<<k) sum += fact[tmp[k]];
                else sum += tmp[k];
            }
            if(fl || sum > s || __builtin_popcount(j) > K) continue;
            for(int k = 0; k <= K-__builtin_popcount(j); k++) res += mm[k][s - sum];

            if(sum == s) res++;
        }
    }

    cout << res << endl;
}