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

map<int,int>mm;
pair<int,int>pp[100001];
int ar[200001], id[200001];
int bit[200001];
void insert(int x){
    for(int i = x; i <= 200000; i += i & -i) bit[i]++;
}
int query(int x){
    int ret = 0;
    for(int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n){
        cin >> pp[i].xx >> pp[i].yy;
        mm[pp[i].xx] = mm[pp[i].yy] = 1;
    }
    int cnt = 0;
    for(auto &v:mm){
        v.yy = ++cnt;
        id[cnt] = v.xx;
    }
    FOR(i, 1, cnt+1) ar[i] = i;
    REP(i, n){
        swap(ar[mm[pp[i].xx]], ar[mm[pp[i].yy]]);
    }
    LL res = 0;
    FOR(i, 1, cnt+1){
        LL v = id[i] - id[i-1] - 1;
        res += (query(200000) - query(i-1)) * v;
        res += query(200000) - query(ar[i]);
        if(ar[i] < i){
            v = id[i] - id[ ar[i] ] - (i-ar[i]);
            res += v;
        }
        insert(ar[i]);
    }
    cout << res << endl;
}