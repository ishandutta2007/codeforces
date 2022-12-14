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

LL seg[400001], id[400001];
void insert(int idx, int s, int e, int p, int v, int ii){
    if(s == e){
        seg[idx] = v;
        id[idx] = ii;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v, ii);
    else insert(idx * 2 + 2, mid + 1, e, p, v, ii);
    if(seg[idx * 2 + 1] > seg[idx * 2 + 2]){
        seg[idx] = seg[idx * 2 + 1];
        id[idx] = id[idx * 2 + 1];
    } else {
        seg[idx] = seg[idx * 2 + 2];
        id[idx] = id[idx * 2 + 2];
    }
}
pair < LL, LL > query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return mp(seg[idx], id[idx]);
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else return max(query(idx * 2 + 1, s, mid, st, mid), query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
}
LL dp[100011], ar[100001], val[100001];
map < LL, LL > mm;
LL lft[100001], rgt[100001], pre[100001];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    FOR(i, 1, a + 1){
        cin >> ar[i];
        if(mm[ar[i]] == 0)val[++e] = ar[i];
        mm[ar[i]] = 1;
    }
    sort(val + 1, val + e + 1);
    c = 1;
    for(int i = 1; i <= e; i++){
        mm[val[i]] = i;
        while(c < i && val[c] <= (val[i] - b)) c++;
        lft[i] = c;
    }
    c = e;
    for(int i = a; i >= 1; i--){
        while(c > i && val[c] >= val[i] + b) c--;
        rgt[i] = c;
    }
    FOR(i, 1, a + 1){
        ar[i] = mm[ar[i]];
    }
    g = h = 0;
    for(int i = a; i >= 1; i--){
        pair < LL, LL > p1 = mp(0, 0), p2 = mp(0, 0);
        if(lft[ar[i]] > 1) p1 = query(0, 1, e, 1, lft[ar[i]] - 1);
        if(rgt[ar[i]] < e) p2 = query(0, 1, e, rgt[ar[i]] + 1, e);
        if(b == 0) p1 = query(0, 1, e, 1, e);
        p1 = max(p1, p2);
        dp[i] = 1 + p1.xx;
        if(p1.yy == 0) pre[i] = -1;
        else pre[i] = p1.yy;
        insert(0, 1, e, ar[i], dp[i], i);
        if(dp[i] > g){
            g = dp[i];
            h = i;
        }
    }
    cout << g << endl;
    for(int i = h; i >= 0; i = pre[i]){
        cout << i << " " ;
    }
    cout << endl;
}