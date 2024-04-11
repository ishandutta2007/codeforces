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
#include<unordered_set>

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

int isp[1000001];
vector < pair < int, int > > vc;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i <= 1000000; i++){
        if(isp[i] == 0){
            for(int j = i * 2; j <= 1000000; j += i) isp[j] = 1;
        }
    }
    int n, k; cin >> n >> k;
    for(int i = 2; i <= 1000000; i++){
        if(i > k || isp[i] || (k % i) != 0) continue;
        int cc = 0;
        while(k % i == 0){
            cc++;
            k /= i;
        }
        vc.pb(mp(i, cc));
    }

    REP(i, n){
        int x; cin >> x;
        REP(j, vc.size()){
            if(vc[j].yy == -1) continue;
            int cc = 0;
            while(x % vc[j].xx == 0){
                cc++;
                x /= vc[j].xx;
            }
            if(cc >= vc[j].yy) vc[j].yy = -1;
        }
    }

    REP(i, vc.size()){
        if(vc[i].yy != -1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}