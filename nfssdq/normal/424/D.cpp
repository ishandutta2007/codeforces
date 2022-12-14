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
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


LL ar[303][303];
int arU[303][303][303], arD[303][303][303];
LL tmp[303];
pair < pair < int, int >, pair < int, int > > fillup(int a, int b, int c, int d){
    return mp(mp(a,b), mp(c,d));
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b >> z;
    LL tu, tp, td; cin >> tp >> tu >> td;
    FOR(i, 1, a + 1){
        FOR(j, 1, b + 1) cin >> ar[i][j];
    }
    for(int j = 1; j <= b; j++){
        for(int k = 1; k <= a; k++){
            for(int l = k + 1; l <= a; l++){
                arU[j][k][l] = arU[j][k][l - 1];
                arD[j][k][l] = arD[j][k][l - 1];
                if(ar[l][j] > ar[l - 1][j]){
                    arU[j][k][l] += td;
                    arD[j][k][l] += tu;
                } else if(ar[l][j] < ar[l - 1][j]){
                    arU[j][k][l] += tu;
                    arD[j][k][l] += td;
                } else {
                    arU[j][k][l] += tp;
                    arD[j][k][l] += tp;
                }
            }
        }
    }
    set < pair < int, int > >ss;
    set < pair < int, int > >::iterator it;
    f = linf;
    pair < pair < int, int >, pair < int, int > > pp;
    for(int i = 1; i <= a; i++){
        for(int j = i + 2; j <= a; j++){
            set0(tmp);
            for(int k = 2; k <= b; k++){
                tmp[k] = tmp[k - 1];
                if(ar[i][k] > ar[i][k - 1]) tmp[k] += tu;
                else if(ar[i][k] < ar[i][k - 1]) tmp[k] += td;
                else tmp[k] += tp;

                if(ar[j][k] > ar[j][k - 1]) tmp[k] += td;
                else if(ar[j][k] < ar[j][k - 1]) tmp[k] += tu;
                else tmp[k] += tp;
            }
            ss.clear();
            e = b - 1;
            if(i + 2 == j) e--;
            for(int k = e + 2; k <= b; k++){
                ss.insert(mp(arD[k][i][j] + tmp[k], k));
            }
            for(int k = e; k >= 1; k--){
                g = z - arU[k][i][j] + tmp[k];
                it = ss.lower_bound(mp(g, 0));
                if(it != ss.end()){
                    pair < int, int > p1 = (*it);
                    p1.xx -= tmp[k] - arU[k][i][j];
                    if(abs(z - p1.xx) < f){
                        f = abs(z - p1.xx);
                        pp = fillup(i, k, j, p1.yy);
                    }
                }
                if(it != ss.begin()){
                    it--;
                    pair < int, int > p1 = (*it);
                    p1.xx -= tmp[k] - arU[k][i][j];
                    if(abs(z - p1.xx) < f){
                        f = abs(z - p1.xx);
                        pp = fillup(i, k, j, p1.yy);
                    }
                }
                ss.insert(mp(tmp[k + 1] + arD[k + 1][i][j], k + 1));
            }
        }
    }
//    cout << f << endl;
    cout << pp.xx.xx << " " << pp.xx.yy << " " << pp.yy.xx << " " << pp.yy.yy << endl;
}