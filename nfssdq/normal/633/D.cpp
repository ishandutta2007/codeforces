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
LL ar[1001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n) cin >> ar[i];
    REP(i, n) mm[ar[i]]++;
    int res = 2;

    int cnt0 = 0;
    REP(i, n) if(ar[i] == 0) cnt0++;
    res = max(res, cnt0);

    REP(i, n){
        REP(j, n){
            if(i == j || (ar[i] == 0 && ar[j] == 0)) continue;
            LL x = ar[i], y = ar[j];
            mm[x]--; mm[y]--;
            int cnt = 1;
            for(int k = 2; ; k++){
                LL tmp = x+y;
                if(mm.count(tmp) == 0 || mm[tmp] == 0){
                    res = max(res, k);
                    break;
                }
                mm[tmp]--;
                x = y; y = tmp;
                cnt = k;
            }
            x = ar[i], y = ar[j];
            mm[x]++;
            mm[y]++;
            for(int k = 2; k <= cnt; k++){
                LL tmp = x+y;
                mm[tmp]++;
                x = y; y = tmp;
            }
        }
    }
    cout << res << endl;

}