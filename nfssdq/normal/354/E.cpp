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
#define PI         2.0*acos(0.0)
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
        if(e & 1) ret = (ret * p);
        p = (p * p);
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL dp[20][7], last[20][6], ar[730][6], sum[730], val[20], tmp[3] = {0, 4, 7};
LL go(int c, int b){
    if(c < 0){
        return b == 0 ? 1 : 0;
    }
    LL &ret = dp[c][b];
    if(ret != -1) return ret;
    ret = 0;
    REP(i, 729){
        int a = b + sum[i];
        int p = a % 10;
        a /= 10;
        if(p != val[c])continue;
        if(go(c - 1, a)){
            last[c][b] = i;
            return ret = 1;
        }
    }
    return ret;
}
void print(int c, int b, vector < LL > vc){
    if(c < 0) {
        REP(i, 6)cout << vc[i] << " " ;
        cout << endl;
        return;
    }
    REP(i, 6){
        vc[i] = ar[last[c][b]][i] * bigmod(10ll, 19ll - c, mod) + vc[i];
    }
    int a = b + sum[last[c][b]];
    print(c - 1, a/10, vc);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    REP(i, 3){
        REP(j, 3){
            REP(k, 3){
                REP(l, 3){
                    REP(m, 3){
                        REP(n, 3){
                            ar[d][0] = tmp[i]; ar[d][1] = tmp[j]; ar[d][2] = tmp[k];
                            ar[d][3] = tmp[l]; ar[d][4] = tmp[m]; ar[d][5] = tmp[n];
                            sum[d++] = tmp[i]+tmp[j]+tmp[k]+tmp[l]+tmp[m]+tmp[n];
                        }
                    }
                }
            }
        }
    }
    cin >> a;
    REP(i, a){
        cin >> b;
        REP(i, 20){
            val[i] = b % 10;
            b /= 10;
        }
        reverse(val, val + 20);
        memset(dp, -1, sizeof dp);
        c = go(19, 0);
        if(c == 0) cout << -1 << endl;
        else {
            vector < LL > vc(6, 0);
            print(19, 0, vc);
        }
    }
}