#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
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
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL ar[100001];

LL go(int v, int N, LL A, LL R, LL M){
    LL lo = 0, hi = 0;
    REP(i, N){
        if(ar[i] < v) lo += v - ar[i];
        else hi += ar[i] - v;
    }
    LL m = min(lo, hi);
    LL res = 0;
    if(A+R < M) res += m * (A+R);
    else res += m * M;
    res += (lo - m) * A;
    res += (hi - m) * R;
    return res; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; LL A, R, M; cin >> N >> A >> R >> M;
    REP(i, N) cin >> ar[i];
    sort(ar, ar + N);
    LL lo = -1, hi = mod;
    while (hi - lo > 1){
        int mid = (hi + lo)>>1;
        if (go(mid, N, A, R, M) < go(mid + 1, N, A, R, M)) hi = mid;
        else lo = mid; 
    }
    cout << go(lo+1, N, A, R, M) << endl;
}