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

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>
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

int ar[1000003], sum[1000003];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, p; cin >> n >> p;
    cin >> s;
    int m = strlen(s);

    Z_algo(m);

    REP(i, p) cin >> ar[i];
    REP(i, p) ar[i]--;
    sort(ar, ar + p);

    REP(i, p){
        if(i == 0 || ar[i-1]+m-1 < ar[i]) ;
        else {
            int v = ar[i]-ar[i-1];
            if(zz[v] != (m-v)){
                cout << 0 << endl;
                return 0;
            }
        }
        sum[ar[i]]++;
        sum[ar[i]+m]--;
    }
    LL cnt = 0;
    REP(i, n){
        if(i) sum[i] += sum[i-1];
        if(sum[i] == 0) cnt++;
    }
    cout << bigmod(26ll, cnt, mod) << endl;
}