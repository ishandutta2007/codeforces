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
#define mod        1000000009ll
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

int ar[400001], tmp[400001];
vector < int > vc, use[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n) cin >> ar[i];
    REP(i, n) ar[i+n] = ar[i];

    FOR(i, 1, n) if(n % i == 0) vc.pb(i);
    FOR(i, 1, n){
        use[gcd(i, n)].pb(i);
    }

    LL res = 0;
    REP(i, vc.size()){
        set0(tmp);
        REP(j, vc[i]){
            int mx = 0;
            for(int k = j; k < n; k += vc[i]) mx = max(mx, ar[k]);
            for(int k = j; k < n; k += vc[i]) if(ar[k] == mx) tmp[k] = 1;
        }
        REP(j, n) tmp[j+n] = tmp[j];

        int st = -1;
        REP(j, n) {
            if(tmp[j] == 0){
                st = j;
                break;
            }
        }
        if(st == -1){
            res += (LL)(use[vc[i]].size()) * (LL)n;
            continue;
        }

        int last = st;
        int cnt = -1;
        for(int j = st + 1; j < st + n; j++){
            if(tmp[j]){
                while(cnt < (int)use[vc[i]].size()-1 && use[vc[i]][cnt+1] <= j - last) cnt++;
//                if(i == 0 && j == 4) cout << use[vc[i]][0] << " " << j-last << endl;
                res += cnt + 1;
            } else {
                last = j;
                cnt = -1;
            }
        }
    }


    cout << res << endl;

}