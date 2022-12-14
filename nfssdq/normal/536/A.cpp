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

LL ar[3000001], A, B;
LL go(LL L, LL M, LL R){
    LL len = (R-L+1);
    if(len <= M) return ar[R];
    LL sum = len * (len - 1) / 2ll; sum *= B;
    sum += len * ar[L];
    return max((sum + M-1) / M, ar[R]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n; cin >> A >> B >> n;
    FOR(i, 1, 3000000+1){
        ar[i] = A + (LL)(i-1)*B;
    }
    while(n--){
        LL L, T, M; cin >> L >> T >> M;
        LL lo = L, hi = 3000000, mid = (lo+hi) / 2ll;
        if(ar[L] > T){
            cout << -1 << endl;
            continue;
        }
        while(lo < mid){
            if(go(L, M, mid) <= T) lo = mid;
            else hi = mid - 1;
            mid = (lo + hi) / 2ll;
        }
        if(go(L, M, mid+1) <= T) mid++;
        cout << mid << endl;
    }
}