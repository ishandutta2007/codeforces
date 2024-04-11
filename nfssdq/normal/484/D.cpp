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

LL seg1[4000001], seg2[4000001], val[1000001];
void insert(int idx, int s, int e, int p, LL b){
    if(s == e){
        seg1[idx] = max(seg1[idx], val[s] + b);
        seg2[idx] = max(seg2[idx], b - val[s]);
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, b);
    else insert(idx * 2 + 2, mid + 1, e, p, b);
    seg1[idx] = max(seg1[idx], val[p] + b);
    seg2[idx] = max(seg2[idx], b - val[p]);
}
LL query1(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg1[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query1(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query1(idx * 2 + 2, mid + 1, e, st, ed);
    else return max(query1(idx * 2 + 1, s, mid, st, mid), query1(idx * 2 + 2, mid + 1, e, mid + 1, ed));
}
LL query2(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg2[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query2(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query2(idx * 2 + 2, mid + 1, e, st, ed);
    else return max(query2(idx * 2 + 1, s, mid, st, mid), query2(idx * 2 + 2, mid + 1, e, mid + 1, ed));
}
LL ar[1000001], dp[1000011];
LL vv[1000001], mm[1000001];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f,g,h = 0,x = 1,y,z;
    cin >> a;
    for(int i = 1; i <= a; i++){
        cin >> ar[i];
        vv[i] = ar[i];
    }
    sort(vv + 1, vv + a + 1);
    for(int i = 1; i <= a; i++){
        mm[i] = lower_bound(vv + 1, vv + a + 1, ar[i]) - vv;
        val[ mm[i]] = ar[i];
    }
    memset(seg1, -5, sizeof seg1);
    memset(seg2, -5, sizeof seg2);
    for(int i = a; i >= 1; i--){
        f = mm[i];
        b = query1(0, 1, a, f, a) - ar[i];
        c = query2(0, 1, a, 1, f) + ar[i];
        dp[i] = max(b, c);
        dp[i] = max(dp[i], dp[i + 1]);
        insert(0, 1, a, f, dp[i + 1]);
    }
    cout << dp[1] << endl;
}