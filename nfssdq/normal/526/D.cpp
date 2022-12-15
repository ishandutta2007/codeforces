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

char s[1000003];
int zz[1000003];

void Z_algo(int n) {
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            zz[i] = R-L;
            R--;
        } else {
            int k = i-L;
            if (zz[k] < R-i+1) zz[i] = zz[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                zz[i] = R-L;
                R--;
            }
        }
    }
}
int ar[1000003];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k >> s;
    Z_algo(n);
    if(k == 1){
        REP(i, n) cout << 1;
        cout << endl;
        return 0;
    }
    for(int i = 1; i < n; i++){
        if(i*k > n) break;
        int c = 1, fl = 0, j;
        for(j = i; j < n; j += i){
            c++;
            if(zz[j] < i){
                fl = 1;
                break;
            }
            if(c == k) break;
        }
        if(fl) continue;
        j += i;
        ar[j-1]++; ar[j]--;
        int v = min(zz[j], i);
        ar[j]++; ar[j+v]--;
    }
    REP(i, n){
        if(i)ar[i] += ar[i-1];
        if(ar[i]) cout << 1;
        else cout << 0;
    }
    cout << endl;
}