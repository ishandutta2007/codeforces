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

vector < int > vc[2001];
int ar[2001], cnt = 0, res[13][2001];
void go(int c, int p){
    if(c > 2000){
        REP(i, p) res[cnt][i] = ar[i];
        cnt++;
        return;
    }
    if(vc[c].size() == 0) go(c + 1, p);
    else if(vc[c].size() == 1){
        ar[p] = vc[c][0];
        go(c + 1, p + 1);
    } else if(vc[c].size() == 2){
        ar[p] = vc[c][0];
        ar[p + 1] = vc[c][1];
        go(c + 1, p + 2);
        if(cnt >= 3) return;
        ar[p] = vc[c][1];
        ar[p + 1] = vc[c][0];
        go(c + 1, p + 2);
    } else {
        REP(i, 3){
            int t = p;
            ar[t++] = vc[c][i];
            REP(j, vc[c].size()){
                if(i == j) continue;
                ar[t++] = vc[c][j];
            }
            go(c + 1, t);
            if(cnt >= 3) return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    REP(i, a){
        cin >> b;
        vc[b].pb(i + 1);
    }
    go(1, 0);
    if(cnt < 3) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        REP(i, 3){
            REP(j, a) cout << res[i][j] << " ";
            cout << endl;
        }
    }
}