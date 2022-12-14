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

typedef pair < int, int > po;
po pp[2001], ar[2001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n; cin >> n;
    REP(i, n) cin >> pp[i].xx >> pp[i].yy;
    LL res = (n*(n-1)*(n-2)) / 6ll, sum = 0;
    REP(i, n){
        int cnt = 0;
        REP(j, n) if(i != j) {
            ar[cnt].xx = pp[j].xx - pp[i].xx;
            ar[cnt].yy = pp[j].yy - pp[i].yy;
            cnt++;
        }
        REP(j, cnt){
            int v = gcd(ar[j].xx, ar[j].yy);
            v = abs(v);
            if(v == 0) continue;
            ar[j].xx /= v;
            ar[j].yy /= v;
        }
        sort(ar, ar + cnt);
        int last = -1;
        for(int j = 0; j < cnt; j++){
            if(j == cnt-1 || ar[j] != ar[j+1]){
                int tot = j - last;
                sum += (tot * (tot - 1)) / 2;
                last = j;
            }
        }
    }
    cout << res-(sum/2) << endl;
}