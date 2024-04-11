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

int go(LL a){
    if(a == 0) return 1;
    int ret = 0;
    while(a){
        ret++;
        a /= 7ll;
    }
    return ret;
}

int tmp[11];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL A, B; cin >> A >> B;
    int cnt1 = go(A-1), cnt2 = go(B-1);
    LL res = 0;
    REP(i, 1<<7){
        if(__builtin_popcount(i) != cnt1+cnt2) continue;
        int cnt = 0;
        REP(j, 7) if(i & 1<<j) tmp[cnt++] = j;
        do{
            LL v1 = 0, v2 = 0;
            REP(j, cnt1) v1 = (v1 * 7ll + tmp[j]);
            REP(j, cnt2) v2 = (v2 * 7ll + tmp[j + cnt1]);
            if(v1 < A && v2 < B) {
                res++;
//                REP(j, cnt) cout << tmp[j] << " ";
//                cout << endl;
            }
        } while(next_permutation(tmp, tmp + cnt1 + cnt2));
    }
    cout << res << endl;
}