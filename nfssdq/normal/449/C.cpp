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


LL isp[100001], ar[100001];
vector < pair < int, int > > vc;
vector < int > vp;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    cin >> a;
    for(int i = 2; i <= a; i++){
        if(isp[i] == 0){
            for(int j = i * 2; j <= a; j += i) isp[j] = 1;
        }
    }
    for(int i = 3; i*2 <= a; i++){
        if(isp[i] == 0){
            b = 0;
            for(int j = i; j <= a; j += i) b += 1 - ar[j];
            vp.clear();
            for(int j = i; j <= a; j += i) {
                if(j == i*2) continue;
                if(ar[j] == 0) vp.pb(j);
                ar[j] = 1;
            }
            if(b % 2 == 0){
                if(ar[i*2] == 0) vp.pb(i*2);
                ar[i*2] = 1;
            }
            for(int j = 0; j < vp.size(); j += 2){
                vc.pb(mp(vp[j], vp[j + 1]));
            }
        }
    }
    vp.clear();
    for(int i = 2; i <= a; i += 2) if(!ar[i])vp.pb(i);
    for(int i = 0; i < vp.size(); i += 2){
        if(i + 1 < vp.size())vc.pb(mp(vp[i], vp[i + 1]));
    }
    cout << vc.size() << endl;
    REP(i, vc.size()){
        cout << vc[i].xx << " " << vc[i].yy << endl;
    }
}