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
#define FOR(I,A,B) for(LL I = (A); I < (B); ++I)
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

LL ar[5001], pr[5001], sum[5001], fin[5001], res[5001];
vector < int > prime;
int isp[100001], fl[10001];
map < int, int > mm;
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f,g,h,x,y,z;
    for(int i = 2; i <= 40000; i++){
        if(isp[i] == 0){
            prime.pb(i);
            for(int j = i * 2; j <= 40000; j += i) isp[j] = 1;
        }
    }
    cin >> a >> b;
    REP(i, a){
        cin >> ar[i];
    }
    REP(i, b) cin >> pr[i];
    REP(i, b){
        for(int j = 0; j < a; j++){
            sum[j] = 0;
            c = ar[j];
            while(c % pr[i] == 0){
                sum[j]++;
                c /= pr[i];
            }
            if(j > 0)sum[j] = min(sum[j], sum[j - 1]);
        }
        for(int j = a - 1; j >= 0; j--){
            fin[j] += sum[j];
        }
    }
    REP(i, b) mm[pr[i]] = 1;
    REP(i, prime.size()){
        if(mm[prime[i]]) fl[i] = 1;
    }
    c = 0;
    for(int i = 0; i < a; i++){
        sum[i] = 0;
        c = gcd(c, ar[i]);
        d = c;
        for(int j = 0; j < prime.size(); j++){
            while(d % prime[j] == 0){
                if(fl[j] == 0) sum[i]++;
                d /= prime[j];
            }
        }
        if(d > 1)
            if(mm[d] == 0)sum[i]++;
    }
    for(int i = a - 1; i >= 0; i--){
        if(fin[i] > sum[i]){
            res[i] += fin[i] - sum[i];
            d = fin[i] - sum[i];
            for(int j = i - 1; j >= 0; j--) {
                res[j] += d;
                fin[j] -= fin[i];
                sum[j] -= sum[i];
            }
        }

    }
    c = 0;
    REP(i, a) {
        for(int j = 0; j < prime.size(); j++){
            d = 1;
            if(fl[j]) d = -1;
            while(ar[i] % prime[j] == 0){
                c += d;
                ar[i] /= prime[j];
            }
        }
        if(ar[i] > 1)
            if(mm[ar[i]]) c--;
            else c++;
        c += res[i];
    }
    cout << c << endl;
}