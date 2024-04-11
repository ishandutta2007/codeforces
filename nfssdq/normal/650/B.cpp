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

LL ar[2][500001];
string s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, a, b, T; cin >> n >> a >> b >> T >> s;
    LL t = 0;
    for(int i = 0; i < n; i++){
        t++;
        if(s[i] == 'w') t += b;
        ar[0][i] = t;
        t += a;
    }
    t = a;
    for(int i = n-1; i >= 1; i--){
        t++;
        if(s[i] == 'w') t += b;
        ar[1][i] = t;
        t += a;
    }

    int rgt = 1;

    int res = 0;
    for(int i = 0; i < n; i++){
        if(ar[0][i] > T) break;
        res = max(res, i+1);
        LL lft = T - ar[0][i] - a*i;
        while(rgt < n && ar[1][rgt] > lft) rgt++;
        if(rgt <= i) rgt = i+1;
        res = max(res, i+1 + (int)n-rgt);
    }

    rgt = n-2;
    for(int i = n-1; i >= 1; i--){
        if(ar[1][i] + ar[0][0] > T) break;
        res = max(res, (int)n-i+1);
        LL lft = T - ar[1][i] - a * (n-i);
        while(rgt > 0 && ar[0][rgt] > lft) rgt--;
        if(rgt >= i) rgt = i-1;
        res = max(res, (int)n-i+rgt+1);
    }

    cout << res << endl;
}