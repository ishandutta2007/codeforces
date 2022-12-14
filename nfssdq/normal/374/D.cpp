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
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL seg[4000001], ar[1000001], val[1000001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid)insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
}
LL query(int idx, int s, int e, int p){
    if(seg[idx] < p)return -1;
    if(s == e)return s;
    int mid = (s + e) / 2;
    if(p <= seg[idx * 2 + 1])return query(idx * 2 + 1, s, mid, p);
    else return query(idx * 2 + 2, mid + 1, e, p - seg[idx * 2 + 1]);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f,g,h = 1,x,y,z;
    cin >> a >> b;
    REP(i, b)cin >> ar[i];
    c = 0;
    REP(i, a){
        cin >> d;
        if(d == -1){
            REP(j, b){
                e = query(0, 1, 1000000, ar[j] - j);
                if(e == -1)break;
                insert(0, 1, 1000000, e, 0);
            }
        }
        else {
            c++;
            val[c] = d;
            insert(0, 1, 1000000, c, 1);
        }
    }
    if(seg[0] == 0)cout << "Poor stack!" << endl;
    else {
        FOR(i, 1, seg[0] + 1){
            e = query(0, 1, 1000000, i);
            cout << val[e];
        }
    }
}