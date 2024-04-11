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
#define linf       (1<<60)-1
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

vector < int > vc[300001];
pair < int, int > cnt[300001];
int ar[300001], val[300001];
main(){
//    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    scanf("%I64d %I64d", &a, &b);
    FOR(i, 1, a + 1){
        cnt[i].yy = i;
        scanf("%I64d %I64d", &c, &d);
        cnt[c].xx++;
        cnt[d].xx++;
        val[c]++;
        val[d]++;
        vc[c].pb(d);
        vc[d].pb(c);
    }
    sort(cnt + 1, cnt + a + 1);
    d = 1;
    for(int i = a; i >= 1; i--){
        if(cnt[i].xx >= b) continue;
        else {
            c = b - cnt[i].xx - 1;
            while(d <= a && cnt[d].xx <= c)d++;
            ar[cnt[i].yy] = d - 1;
        }
    }
    for(int i = 1; i <= a; i++){
        if(vc[i].size() > 0) sort(vc[i].begin(), vc[i].end());
        c = 0, d = 0, e = 0, h = 0;
        for(int j = 0; j < vc[i].size(); j++){
            if(vc[i][j] != d) {
                if(j > 0){
                    if(val[d] > (b - val[i] - 1)) h++;
                    g = val[i] + val[d] - e;
                    if(g >= b) f++;
                }
                e = 1;
                c++;
                d = vc[i][j];
            } else e++;
        }
        if(vc[i].size() > 0){
            g = val[i] + val[d] - e;
            if(g >= b) f++;
            if(val[d] > (b - val[i] - 1)) h++;
        }
        if(val[i] > (b - val[i] - 1)) h++;
        if(val[i] >= b) f += a - c - 1;
        else f += a - ar[i] - h;
    }
    cout << f/2ll << endl;
}