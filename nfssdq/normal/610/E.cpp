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

int lzy[200001 * 4], n, k;
int seg[200001*4][11][11], seg2[200001 * 4][2];
void update(int idx, int s, int e){
    if(s == e){
        lzy[idx] = 0;
        return;
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++) seg[idx*2+1][i][j] = seg[idx*2+2][i][j] = 0;
    }
    int mid = (s + e) / 2;
    seg[idx * 2 + 1][ lzy[idx] ][ lzy[idx] ] = mid - s;
    seg[idx * 2 + 2][ lzy[idx] ][ lzy[idx] ] = e - mid - 1;
    lzy[idx * 2 + 1] = lzy[idx * 2 + 2] = lzy[idx];
    seg2[idx * 2 + 1][0] = seg2[idx * 2 + 1][1] = lzy[idx];
    seg2[idx * 2 + 2][0] = seg2[idx * 2 + 2][1] = lzy[idx];
    lzy[idx] = 0;
}
void insert(int idx, int s, int e, int st, int ed, int v){
    if(lzy[idx]) update(idx, s, e);
    if(s == st && e == ed){
        lzy[idx] = v;
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= k; j++) seg[idx][i][j] = 0;
        }
        seg[idx][v][v] = (e - s);
        seg2[idx][0] = seg2[idx][1] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid) insert(idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        insert(idx * 2 + 1, s, mid, st, mid, v);
        insert(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
    }

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++) {
            seg[idx][i][j] = seg[idx*2+1][i][j] + seg[idx*2+2][i][j];
        }
    }
    seg[idx][ seg2[idx*2+1][1] ][ seg2[idx*2+2][0] ]++;
    seg2[idx][0] = seg2[idx * 2 + 1][0];
    seg2[idx][1] = seg2[idx * 2 + 2][1];
}

string s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> n >> q >> k;
    cin >> s;
    FOR(i, 1, s.size()+1){
        insert(0, 1, n, i, i, s[i-1]-'a'+1);
    }
    while(q--){
        int typ; cin >> typ;
        if(typ == 1){
            int l, r; string v; cin >> l >> r >> v;
            insert(0, 1, n, l, r, v[0] - 'a' + 1);
        } else {
            string t; cin >> t;
            int res = 0;
            for(int i = 1; i <= k; i++){
                for(int j = 1; j <= k; j++){
                    int st = -1, ed = -1;
                    for(int l = 0; l < t.size(); l++){
                        if(t[l]-'a'+1 == i) st = l;
                        if(t[l]-'a'+1 == j) ed = l;
                    }
                    if(ed <= st) res += seg[0][i][j];
                }
            }
            cout << res+1 << "\n";
        }
    }
}
/*
5 5 3
abcba
2 abc
1 1 5 b
1 1 1 a
1 3 3 c
2 abc

*/