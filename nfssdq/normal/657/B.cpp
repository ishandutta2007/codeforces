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

LL ar[200001], A[200001], B[200001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    REP(i, n+1) {
        cin >> ar[i];
        A[i] = B[i] = ar[i];
    }
    int st = n;
    for(int i = 0; i <= n; i++){
        st = i;
        if(i < n && abs(A[i]) % 2 == 0){
            A[i + 1] += (A[i] / 2);
        } else {
            break;
        }
    }

    int ed = 0;
    for(int i = n; i >= 1; i--){
        if(abs(B[i]) > mod * 1000000ll){
            ed = i;
            break;
        }
        B[i-1] += B[i] * 2ll;
    }

    int res = 0;
    for(int i = ed; i <= st; i++){
        LL v = B[i] + A[i] - ar[i] * 2ll;
        if(abs(v) > k || v == -ar[i] || (v == 0 && i == n)) continue;
        res++;
    }

    cout << res << endl;
}