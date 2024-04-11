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

LL ar[300001], fl[300001];
string ss;
deque < int > vc;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    FOR(i, 1, n + 1) {
        cin >> ss;
        if(ss == "?"){
            fl[i] = 1;
            continue;
        }
        istringstream is(ss);
        is >> ar[i];
    }
    for(int i = 1; i <= k; i++) ar[i + n] = 2000000000ll;
    for(int i = 1; i <= k; i++){
        LL last = -2000000000ll, lid = i - k;
        for(int j = i; j <= n + k; j += k){
            if(j <= n && fl[j]) continue;
            LL range = ar[j] - last - 1;
            int nv = (j - lid) / k; nv--;
            if(nv > range){
                cout << "Incorrect sequence" << endl;
                return 0;
            }
            vc.clear();
            if(last >= 0) {
                for(int l = 1; l <= nv; l++) vc.pb(last + l);
            } else if(ar[j] < 0){
                for(int l = 1; l <= nv; l++) vc.push_front(ar[j] - l);
            } else {
                 LL lo = 0, hi = 1;
                 if(ar[j] == 0){
                    lo = -1, hi = 0;
                 }
                 REP(l, nv){
                    if(hi >= ar[j] || ( abs(lo) <= abs(hi) && lo > last) )
                        vc.push_front(lo--);
                    else vc.pb(hi++);
                 }
            }
            int c = 0;
            for(int l = lid + k; l < j; l += k){
                ar[l] = vc[c++];
            }
            last = ar[j];
            lid = j;
        }
    }
    FOR(i, 1, n + 1) cout << ar[i] << " ";
    cout << endl;

}