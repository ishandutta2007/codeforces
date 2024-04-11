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
#define ALL(A)     (A).begin(), (A).end()
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


LL ar[1000001], fact[1000001], sum[1000001], bit[1000001];
void insert(int x){
    for(int i = x; i <= 1000000; i += i & -i) bit[i]++;
}
LL query(int x){
    LL ret = 0;
    for(int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z = 0;
    cin >> a;
    fact[0] = 1;
    for(LL i = 1; i <= a; i++) fact[i] = (fact[i - 1] * i) % mod;
    for(LL i = 2; i <= a; i++){
        sum[i] = (sum[i - 1] * i) % mod;
        b = (i - 1) * i * (i - 1) / 2ll; b %= mod;
        b = (b * fact[i - 2]) % mod;
        sum[i] = (sum[i] + b) % mod;
    }
    for(int i = 1; i <= a; i++) cin >> ar[i];
    b = 0;
    for(int i = 1; i <= a; i++){
        c = ar[i] - query(ar[i]) - 1;
        e = (c * (c - 1) / 2) % mod;
        e = (((b*c + e)%mod) * fact[a - i]) % mod;
        d = (d + e) % mod;
        d = (d + sum[a - i]*c) % mod;
        insert(ar[i]);
        b += c;
    }
    cout << (d+b)%mod << endl;
}