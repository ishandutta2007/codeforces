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

vector < int > prime;
vector < pair < int, int > > out;
int isp[100001], pos[100001], ar[100001];
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    for(int i = 2; i <= 100000; i++){
        if(isp[i] == 0){
            prime.pb(i);
            for(int j = i * 2; j <= 100000; j += i) isp[j] = 1;
        }
    }
    cin >> a;
    REP(i, a){
        cin >> b;
        pos[b] = i + 1;
        ar[i + 1] = b;
    }
    FOR(i, 1, a + 1){
        b = pos[i] - i + 1;
        while(b >= 2){
            c = upper_bound(prime.begin(), prime.end(), b) - prime.begin();
            c--;
            d = pos[i] - prime[c] + 1;
//            cout << b << " " << prime[c] << " " << d << " " << pos[i] <<  " " << i << endl;
            out.pb(mp(d, pos[i]));
            swap(ar[pos[i]], ar[d]);
            swap(pos[i], pos[ar[pos[i]]]);
            b = pos[i] - i + 1;
        }
    }
    cout << out.size() << endl;
    REP(i, out.size()) cout << out[i].xx << " " << out[i].yy << endl;
}