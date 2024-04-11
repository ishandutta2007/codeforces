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



template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL ar[22][100001], sum[22];
LL seg[22][400001];
void insert(int ii, int idx, int s, int e, int p, int v){
    if(s == e){
        seg[ii][idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid)insert(ii, idx * 2 + 1, s, mid, p, v);
    else insert(ii, idx * 2 + 2, mid + 1, e, p, v);
    seg[ii][idx] = seg[ii][idx * 2 + 1] + seg[ii][idx * 2 + 2];
}
int QL(int ii, int idx, int s, int e, int st, int ed){
    if(ed < st || seg[ii][idx] == 0)return 1000000;
    if(s == e)return s;
    int mid = (s + e) / 2;
    if(ed <= mid)return QL(ii, idx * 2 + 1, s, mid, st, ed);
    else if(st > mid)return QL(ii, idx * 2 + 2, mid + 1, e, st, ed);
    else {
        int a = QL(ii, idx * 2 + 1, s, mid, st, mid);
        if(a < 1000000) return a;
        return QL(ii, idx * 2 + 2, mid + 1, e, mid + 1, ed);
    }
}
int QR(int ii, int idx, int s, int e, int st, int ed){
    if(ed < st || seg[ii][idx] == 0)return -1;
    if(s == e)return s;
    int mid = (s + e) / 2;
    if(ed <= mid)return QR(ii, idx * 2 + 1, s, mid, st, ed);
    else if(st > mid)return QR(ii, idx * 2 + 2, mid + 1, e, st, ed);
    else {
        int a = QR(ii, idx * 2 + 2, mid + 1, e, mid + 1, ed);
        if(a >= 0) return a;
        return QR(ii, idx * 2 + 1, s, mid, st, mid);
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    REP(i, a){
        cin >> d;
        REP(j, 20){
            ar[j][i] = d % 2;
            d /= 2;
        }
    }
    for(int i = 0; i < 20; i++){
        c = 0;
        for(int j = 0; j < a; j++){
            if(ar[i][j] == 0){
                sum[i] += c * (c + 1ll) / 2ll;
                c = 0;
                insert(i, 0, 0, a - 1, j, 1);
            } else c++;
        }
        sum[i] += c * (c + 1ll) / 2ll;
    }
    REP(i, b){
        cin >> c >> d;
        c--; h = 0;
        REP(j, 20){
            e = d % 2;
            d /= 2;
            if(ar[j][c] == e){
                h += sum[j] * (1ll<<j);
                continue;
            }
            if(ar[j][c] == 0){
                x = QR(j, 0, 0, a - 1, 0, c - 1);
                y = QL(j, 0, 0, a - 1, c + 1, a - 1);
                y = min(y, a);
                f = (c - x) * (c - x - 1ll) / 2ll;
                f += (y - c) * (y - c - 1ll) / 2ll;
                sum[j] -= f; f = (y - x - 1);
                sum[j] += f * (f + 1ll) / 2;
                insert(j, 0, 0, a - 1, c, 0);
            } else {
                x = QR(j, 0, 0, a - 1, 0, c - 1);
                y = QL(j, 0, 0, a - 1, c + 1, a - 1);
                y = min(y, a);
                x++; y--;
                f = (y - x + 1);
                sum[j] -= f * (f + 1) / 2ll;
                f = (c - x) * (c - x + 1ll) / 2ll;
                f += (y - c) * (y - c + 1ll) / 2ll;
                sum[j] += f;
                insert(j, 0, 0, a - 1, c, 1);
            }
            ar[j][c] = e;
            h += sum[j] * (1ll<<j);
        }
        cout << h << endl;
    }
}