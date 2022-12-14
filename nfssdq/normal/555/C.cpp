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


map < int, int > mm;
typedef pair<int,int> pii;
pii pp[200001], qq[200001];
int fl[200001];
int seg[2][2000001];
void insert(int f, int idx, int s, int e, int st, int ed, int v){
    if(st > ed) return;
    if(s == st && e == ed){
        seg[f][idx] = max(seg[f][idx], v);
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert(f, idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid)insert(f, idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        insert(f, idx * 2 + 1, s, mid, st, mid, v);
        insert(f, idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
    }
}
int query(int f, int idx, int s, int e, int p){
    if(s == e) return seg[f][idx];
    int mid = (s + e) / 2;
    if(p <= mid) return max(seg[f][idx], query(f, idx * 2 + 1, s, mid, p));
    else return max(seg[f][idx], query(f, idx * 2 + 2, mid + 1, e, p));
}
LL ar[400001];
map < pii, int > mc;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    FOR(i, 1, q + 1){
        cin >> pp[i].xx >> pp[i].yy;
        string s; cin >> s;
        if(s == "L") fl[i] = 1;
        mm[pp[i].xx] = 1;
        mm[pp[i].yy] = 1;
        swap(pp[i].xx, pp[i].yy);
    }
    int cnt = 0;
    for(auto &v : mm){
        v.yy = ++cnt;
        ar[cnt] = v.xx;
    }
    FOR(i, 1, q + 1){
        qq[i] = mp( mm[pp[i].xx], mm[pp[i].yy] );
        if(mc[qq[i]]){
            cout << 0 << endl;
            continue;
        }
        mc[qq[i]] = 1;
        if(fl[i] == 0){
            int v = query(0, 0, 1, cnt, qq[i].yy);
            cout << ar[qq[i].xx] - ar[v] << endl;
            insert(1, 0, 1, cnt, v + 1, qq[i].xx, qq[i].yy);
        } else {
            int v = query(1, 0, 1, cnt, qq[i].xx);
            cout << ar[qq[i].yy] - ar[v] << endl;
            insert(0, 0, 1, cnt, v + 1, qq[i].yy, qq[i].xx);
        }
    }

}