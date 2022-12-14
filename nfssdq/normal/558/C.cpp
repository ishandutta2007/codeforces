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


int ar[100001], len[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int mn = 22;
    FOR(i, 1, n + 1) {
        cin >> ar[i];
        REP(j, 22) if(ar[i] & 1<<j) len[i] = j;
        mn = min(mn, len[i]);
    }

    int cnt = mn + 1;
    for(int i = mn; i >= 0; i--){
        int fl = 0;
        int v = ar[1] & 1<<(len[1]-mn+i);
        FOR(j, 1, n + 1){
            if(v && (ar[j] & 1<<(len[j]-mn+i)) == 0) fl = 1;
            if(!v && (ar[j] & 1<<(len[j]-mn+i))) fl = 1;
        }
        if(fl){
            cnt = mn - i;
            break;
        }
    }

    int norm = 0;
    for(int i = 1; i <= n; i++){
        int p = -1;
        for(int j = 0; j <= len[i]-cnt; j++){
            if(ar[i] & 1<<j) p = j;
        }
        while(p >= 0) {
            ar[i] /= 2;
            len[i]--;
            norm++;
            p--;
        }
    }

    int res = 3000000;
    for(int i = 20; i >= 0; i--){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            sum += abs(len[j] - i);
        }
        res = min(res, sum);
    }
    cout << res + norm << endl;

}