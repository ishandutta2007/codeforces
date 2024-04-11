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

int deg[1000];
vector < pair < int, int > > vc;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k; cin >> k;
    if(k % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }
    int n = (k + k-1 + 2);
    for(int i = 1; i <= n*2; i++) deg[i] = k;
    for(int i = 2; i <= k; i++) {
        vc.pb(mp(1, i));
        vc.pb(mp(n + 1, n + i));
        deg[1]--;
        deg[i]--;
    }
    for(int i = k + 1; i <= k + k; i++){
        vc.pb(mp(k + k + 1, i));
        vc.pb(mp(n + k + k + 1, n + i));
        deg[k + k + 1]--;
        deg[i]--;
    }
    for(int i = 2; i <= k; i++){
        for(int j = 1; j <= k; j++){
            if(j == i) continue;
            deg[i]--;
            deg[j + k]--;
            vc.pb(mp(i, j + k));
            vc.pb(mp(n + i, n + j + k));
        }
    }
    int last = 0;
    for(int i = k + 1; i <= k + k; i++){
        if(deg[i]){
            if(last){
                vc.pb(mp(last, i));
                vc.pb(mp(n+last, n+i));
                last = 0;
            } else last = i;
        }
    }
    vc.pb(mp(1, n + 1));
    if(k == 1){
        cout << "YES" << endl;
        cout << 2 << " " << 1 << endl;
        cout << "1 2" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << n*2 << " " << vc.size() << endl;
    REP(i, vc.size()) cout << vc[i].xx << " " << vc[i].yy << endl;
}