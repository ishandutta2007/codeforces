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

vector < pair < LL, LL > > vc;
void ok(LL v){
    if(v <= 2) return;
    LL tmp = v;
    v--;
    LL p = 0;
    for(LL i = 2; i*i <= v; i++){
        if(v % i == 0) {
            p = i;
            break;
        }
    }
    if(p == 0) p = v;
    while(v % p == 0) v /= p;
    if(v > 1) return;
    vc.pb(mp(p, tmp));
}
unordered_map < LL, LL > mm;
int id[100001];
int dp[5000][7000];
int go(LL v, LL p){
    if(p == vc.size()){
        if(v == 1) return 1;
        return 0;
    }
    LL c = mm[v];
    int &ret = dp[p][c];
    if(ret != -1) return ret;
    ret = 0;
    ret += go(v, p+1);
    if(v % vc[p].yy == 0){
        ret += go(v / vc[p].yy, id[p]);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL A; cin >> A;
    if(A == 1){
        cout << 1 << endl;
        return 0;
    }
    for(LL i = 1; i*i <= A; i++){
        if(A % i == 0){
            ok(i);
            mm[i] = 1;
            if(i*i == A) continue;
            ok(A/i);
            mm[A/i] = 1;
        }
    }
    vsort(vc);
    if(vc.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    REP(i, vc.size()){
        id[i] = i;
        for(int j = i + 1; j < vc.size(); j++){
            if(vc[j].xx != vc[i].xx){
                id[i] = j;
                break;
            }
        }
        if(id[i] == i) id[i] = vc.size();
    }

    int cnt = 0;
    for(auto &v:mm){
        v.yy = ++cnt;
    }

    memset(dp, -1, sizeof dp);
    cout << go(A, 0) << endl;
}