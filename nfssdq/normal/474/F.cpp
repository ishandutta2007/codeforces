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
#define ALL(A)     A.begin(), A.end()
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

LL seg[400001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = gcd(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
int query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else return gcd(query(idx * 2 + 1, s, mid, st, mid), query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
}
pair < pair < int, int >, pair < int, int > > pp[100001];
LL ar[100001], res[100001];
map < LL, LL > mm;
vector < LL > vc[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> ar[i];
        insert(0, 1, a, i, ar[i]);
        mm[ar[i]] = 1;
    }
    cin >> b;
    REP(i, b){
        cin >> pp[i].xx.yy >> pp[i].xx.xx;
        pp[i].yy.xx = i;
        pp[i].yy.yy = query(0, 1, a, pp[i].xx.yy, pp[i].xx.xx);
        mm[pp[i].yy.yy] = 1;
    }
    sort(pp, pp + b);
    for(map<LL,LL>::iterator it = mm.begin(); it!= mm.end(); it++){
        (*it).yy = ++d;
    }
    FOR(i, 1, a + 1) ar[i] = mm[ar[i]];
    c = 0;
    REP(i, b){
        for(int j = c + 1; j <= pp[i].xx.xx; j++){
            vc[ar[j]].pb(j);
        }
        c = pp[i].xx.xx;
        pp[i].yy.yy = mm[pp[i].yy.yy];
        f = pp[i].yy.yy;
        e = lower_bound(vc[f].begin(), vc[f].end(), pp[i].xx.yy) - vc[f].begin();
        res[pp[i].yy.xx] = vc[f].size() - e;
        res[pp[i].yy.xx] = pp[i].xx.xx - pp[i].xx.yy + 1 - res[pp[i].yy.xx];
    }
    REP(i, b) cout << res[i] << endl;
}