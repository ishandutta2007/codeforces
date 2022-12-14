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

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>
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

int seg[61][400001], id[61][400001], ar[100001];
void build(int idx, int s, int e){
    if(s == e){
        REP(i, 60){
            if(i % ar[s] == 0){
                seg[i][idx] = 2;
                id[i][idx] = (i+2) % 60;
            } else {
                seg[i][idx] = 1;
                id[i][idx] = (i + 1) %60;
            }
        }
        return;
    }
    int mid = (s + e) / 2;
    build(idx * 2 + 1, s, mid);
    build(idx * 2 + 2, mid + 1, e);
    REP(i, 60){
        seg[i][idx] = seg[i][idx * 2 + 1] + seg[ id[i][idx * 2 + 1] ][idx * 2 + 2];
        id[i][idx] = id[ id[i][idx * 2 + 1] ][idx * 2 + 2];
    }
}
void insert(int idx, int s, int e, int p){
    if(s == e){
        REP(i, 60){
            if(i % ar[s] == 0){
                seg[i][idx] = 2;
                id[i][idx] = (i+2) % 60;
            } else {
                seg[i][idx] = 1;
                id[i][idx] = (i + 1) %60;
            }
        }
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p);
    else insert(idx * 2 + 2, mid + 1, e, p);
    REP(i, 60){
        seg[i][idx] = seg[i][idx * 2 + 1] + seg[ id[i][idx * 2 + 1] ][idx * 2 + 2];
        id[i][idx] = id[ id[i][idx * 2 + 1] ][idx * 2 + 2];
    }
}
pair < int, int > query(int c, int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return mp(id[c][idx], seg[c][idx]);
    int mid = (s + e) / 2;
    if(ed <= mid) return query(c, idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(c, idx * 2 + 2, mid + 1, e, st, ed);
    else {
        pair < int, int > p1 = query(c, idx * 2 + 1, s, mid, st, mid);
        pair < int, int > p2 = query(p1.xx, idx * 2 + 2, mid + 1, e, mid + 1, ed);
        return mp(p2.xx, p1.yy+p2.yy);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    FOR(i, 1, a + 1) cin >> ar[i];
    build(0, 1, a);
    cin >> b; string s;
    REP(i, b){
        cin >> s >> c >> d;
        if(s == "C"){
            ar[c] = d;
            insert(0, 1, a, c);
        } else {
            pair < int, int > pp = query(0, 0, 1, a, c, d - 1);
            cout << pp.yy << "\n";
        }
    }
}