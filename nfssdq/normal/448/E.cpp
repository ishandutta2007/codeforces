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

vector < LL > prime, pp, tmp, dd;
map < LL, LL > mm;
LL isp[1000001];
LL ar[200001], pc[55], cnt = 0;
vector < int > vc[1000001];
void calc(int c, LL v){
    if(c == pp.size()){
        dd.pb(v);
        return;
    }
    for(int i = 0; i <= pc[c]; i++){
        calc(c + 1, v);
        v *= pp[c];
    }
}
void go(LL a, LL b){
    if(cnt >= 100000) return;
    if(b == 0){
        ar[cnt++] = tmp[a];
        return;
    }
    if(a == 0){
        ar[cnt++] = tmp[a];
        return;
    }
    REP(i, vc[a].size()){
        go(vc[a][i], b - 1);
        if(cnt >= 100000) return;
    }
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f,g,h = 0,x,y,z;
    for(int i = 2; i <= 1000000; i++){
        if(isp[i] == 0){
            prime.pb(i);
            for(int j = i * 2; j <= 1000000; j += i) isp[j] = 1;
        }
    }
    cin >> a >> b;
    if(a == 1){
        cout << 1 << endl;
        return 0;
    }
    if(b >= 100000){
        REP(i, 100000) cout << 1 << " ";
        cout << endl;
        return 0;
    }
    LL tt = a;
    REP(i, prime.size()){
        if(tt % prime[i] == 0) pp.pb(prime[i]);
        while(tt % prime[i] == 0) tt /= prime[i];
    }
    if(tt > 1) pp.pb(tt);
    c = sqrt(a);
    for(int i = 1; i <= c; i++){
        if(a % i == 0){
            tmp.pb(i);
            if(a != i*i) tmp.pb(a/i);
        }
    }
    vsort(tmp);
    REP(i, tmp.size()){
        mm[tmp[i]] = i + 1;
    }
    REP(i, tmp.size()){
        set0(pc);
        REP(j, pp.size()){
            c = pp[j];
            while(tmp[i] % c == 0){
                c *= pp[j];
                pc[j]++;
            }
        }
        dd.clear();
        calc(0, 1);
        vsort(dd);
        REP(j, dd.size()){
            c = mm[dd[j]] - 1;
            vc[i].pb(c);
        }
    }
    go(tmp.size() - 1, b);
    cnt = min(cnt, 100000ll);
    REP(i, cnt) cout << ar[i] << " ";
    cout << endl;
}
/*
963761198400 99999
*/