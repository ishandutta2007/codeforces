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

LL n, A, cf, cm, m, ar[100011], val[100011];
pair < LL, LL > pp[100011];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> A >> cf >> cm >> m;
    REP(i, n) {
        cin >> ar[i];
        pp[i].xx = ar[i];
        pp[i].yy = i;
    }

    sort(ar, ar + n);
    sort(pp, pp + n);

    LL last = 0;
    LL cost = 0, sum = 0;
    for(LL i = 0; i < n; i++){
        if(i > 0) cost += (ar[i] - ar[i-1]) * i;
        if(cost <= m) last = i;
        else {
            cost -= (ar[i] - ar[i-1]) * i;
            break;
        }
    }

    LL mxid = n, mxlast = last, mxcost = cost;
    LL tmp = ar[last];
    LL lim = A;
    if(last < n - 1) lim = ar[last + 1];

    tmp = (m - cost) / (last + 1);
    tmp = min(lim, tmp + ar[last]);

    LL res = tmp * cm;
    LL act_m = m;

    for(LL i = n-1; i >= 0; i--){
        m -= A - ar[i];
        if(m < 0) break;

        while(last >= 0){
            if(last >= i || cost > m){
                if(last > 0) cost -= (ar[last] - ar[last-1]) * last;
                last--;
            } else break;
        }

        if(i == 0){
            if(n*cf + A*cm > res){
                res = max(res, n*cf + A*cm);
                mxid = 0;
                mxlast = -1;
                mxcost = cost;
            }
            continue;
        }

        LL v = m - cost;
        v /= (last + 1);
        tmp = ar[last + 1];
        if(i == last + 1) tmp = A;
        LL d = min(tmp, ar[last] + v);
        if((n-i) * cf + d * cm > res){
            res = (n-i) * cf + d * cm;
            mxid = i;
            mxlast = last;
            mxcost = cost;
        }
    }

    cout << res << endl;

    for(int i = n-1; i >= mxid; i--){
        act_m -= A - ar[i];
        val[ pp[i].yy ] = A;
    }

    if(mxid == 0){
        REP(i, n) cout << val[i] << " ";
        cout << endl;
        return 0;
    }

    if(mxid == n){
        if(cm != 0) res /= cm;
        REP(i, mxlast + 1) val[ pp[i].yy ] = max(ar[i], res);
        for(int i = mxlast + 1; i < n; i++) val[pp[i].yy] = ar[i];
        REP(i, n) cout << val[i] << " ";
        cout << endl;
        return 0;
    }

    LL v = act_m - mxcost;
    v /= (mxlast + 1);
    tmp = ar[mxlast + 1];
    if(mxid == mxlast + 1) tmp = A;
    LL d = min(tmp, ar[mxlast] + v);
    for(int i = 0; i <= mxlast; i++){
        val[ pp[i].yy ] = max(d, ar[i]);
    }

    for(int i = mxlast + 1; i < mxid; i++) val[ pp[i].yy ] = ar[i];

    REP(i, n) cout << val[i] << " " ;
    cout << endl;
}