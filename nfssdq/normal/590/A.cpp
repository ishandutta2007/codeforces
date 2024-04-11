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


int ar[500001], on[500001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    FOR(i, 1, n+1) cin >> ar[i];
    on[1] = on[n] = 1;

    for(int i = 2; i < n; i++){
        if(ar[i-1] == ar[i] || ar[i+1] == ar[i]) on[i] = 1;
    }

    int last = ar[1], cnt = 0, pos = 1, res = 0;
    for(int i = 2; i <= n; i++){
        if(on[i]) {
            if(on[i-1] == 0){
                if(last == 1 && ar[i] == 1){
                    res = max(res, cnt+1);
                    for(int j = pos + 1; j < i; j++) ar[j] = 1;
                } else if(last == 0 && ar[i] == 0){
                    res = max(res, cnt);
                    for(int j = pos + 1; j < i; j++) ar[j] = 0;
                } else if(last == 1 && ar[i] == 0){
                    res = max(res, cnt);
                    for(int j = pos + 1; j <= pos + cnt; j++) ar[j] = 1;
                    for(int j = pos + cnt + 1; j < i; j++) ar[j] = 0;
                } else {
                    res = max(res, cnt);
                    for(int j = i - 1; j >= i - cnt; j--) ar[j] = 1;
                    for(int j = pos + 1; j < i - cnt; j++) ar[j] = 0;
                }
            }

            last = ar[i];
            pos = i;
            cnt = 0;
            continue;
        } else {
            cnt += ar[i];
        }

    }

    cout << res << endl;
    FOR(i, 1, n+1) cout << ar[i] << " ";
    cout << endl;

}