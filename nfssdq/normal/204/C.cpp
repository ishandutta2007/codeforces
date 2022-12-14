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


string s1, s2;
vector < int > vc1[27], vc2[27];
int main() {
//    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    cin >> s1 >> s2;
    REP(i, s1.size()){
        vc1[s1[i]-'A'].pb(i);
        vc2[s2[i]-'A'].pb(i);
    }
    double p = 0, res = 0;
    FOR(i, 1, a + 1) p += (double)i * (double)i;
    REP(i, 26){
        double lft = 0.0, rgt = 0.0;
        REP(j, vc2[i].size()){
            rgt += (double)(a - vc2[i][j]);
        }
        c = 0;
        for(int j = 0; j < vc1[i].size(); j++){
            while(c < vc2[i].size() && vc2[i][c] < vc1[i][j]){
                lft += (double)(vc2[i][c] + 1);
                rgt -= (double)(a - vc2[i][c]);
                c++;
            }
            res += (lft*(double)(a - vc1[i][j]) + rgt*(double)(vc1[i][j] + 1)) / p;
        }
    }
    cout << fixed << setprecision(8) << res << endl;
}