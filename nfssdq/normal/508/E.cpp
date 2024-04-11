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

LL dp[604][604];
pair < LL, LL > pp[604];
LL go(int l, int r){
    if(l > r) return 1;
    if(l == r){
        if(pp[l].xx > 1) return 0;
        return 1;
    }
    LL &ret = dp[l][r];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = pp[l].xx; i <= pp[l].yy; i += 2){
        if(i+1 > (r-l+1)*2) break;
        int c = (i - 1) / 2;
        ret |= (go(l + 1, l + c) & go(l + c + 1, r));
    }
    return ret;
}
string print(int l, int r){
    if(l > r) return "";
    if(l == r){
        return "()";
    }
    string ret = "";
    for(int i = pp[l].xx; i <= pp[l].yy; i += 2){
        if(i+1 > (r-l+1)*2) break;
        int c = (i - 1) / 2;
        int d = (go(l + 1, l + c) & go(l + c + 1, r));
        if(d){
            ret += "(" + print(l+1, l+c) + ")" + print(l+c+1, r);
            return ret;
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c=0,d,e = 0,f = 0,g = 0,h = 0,x,y,z;
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> pp[i].xx >> pp[i].yy;
        if(pp[i].xx % 2 == 0) pp[i].xx++;
        if(pp[i].yy % 2 == 0) pp[i].yy--;
        if(pp[i].xx > pp[i].yy){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    memset(dp, -1, sizeof dp);
    if(go(1, a) == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << print(1, a) << endl;
}