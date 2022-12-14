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

int isp[5000001];
int ispal(int n){
    vector < int > vc;
    while(n){
        vc.pb(n%10);
        n /= 10;
    }
    REP(i, vc.size()){
        if(vc[i] != vc[vc.size()-i-1]) return 0;
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL prime = 0, pal = 1, p, q, last = 1;
    for(int i = 2; i <= 5000000; i++){
        if(isp[i] == 0){
            for(int j = i * 2; j <= 5000000; j += i) isp[j] = 1;
        }
    }
    cin >> p >> q;
    for(int i = 2; i <= 5000000; i++){
        prime += isp[i] ^ 1;
        pal += ispal(i);
        if(prime*q <= p*pal){
            last = i;
        }
    }
    cout << last << endl;
}