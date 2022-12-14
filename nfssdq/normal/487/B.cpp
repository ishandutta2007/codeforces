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

int seg[400001][3], ar[100001], dp[100001];
void insert(int idx, int s, int e, int p, int t, int v){
   if(s == e){
        seg[idx][t] = v;
        return;
   }
   int mid = (s + e) / 2;
   if(p <= mid) insert(idx * 2 + 1, s, mid, p, t, v);
   else insert(idx * 2 + 2, mid + 1, e, p, t, v);
   seg[idx][0] = max(seg[idx * 2 + 1][0], seg[idx * 2 + 2][0]);
   seg[idx][1] = min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][1]);
   seg[idx][2] = min(seg[idx * 2 + 1][2], seg[idx * 2 + 2][2]);
}
int query(int idx, int s, int e, int st, int ed, int t){
    if(st > ed) return t == 0 ? 0 : 1000000;
    if(s == st && e == ed) return seg[idx][t];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed, t);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed, t);
    else {
        int l = query(idx * 2 + 1, s, mid, st, mid, t);
        int r = query(idx * 2 + 2, mid + 1, e, mid + 1, ed, t);
        if(t == 0) return max(l, r);
        else return min(l, r);
    }
}
int main() {
//    freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = -INT_MAX,f = INT_MAX,g,h = 0,x,y,z = 0;
    cin >> a >> b >> c;
    FOR(i, 1, a + 1) cin >> ar[i];
    d = a;
    if(c > a){
        cout << -1 << endl;
        return 0;
    }
    insert(0, 1, a + 1, a + 1, 2, 0);
    d = a;
    for(int i = a; i >= 1; i--){
        insert(0, 1, a + 1, i, 0, ar[i]);
        insert(0, 1, a + 1, i, 1, ar[i]);
        while(d >= i+c){
            g = query(0, 1, a + 1, i, d, 0);
            h = query(0, 1, a + 1, i, d, 1);
            if(g - h > b) d--;
            else break;
        }
        dp[i] = 1000000;
        if(d < i+c-1){
            insert(0, 1, a + 1, i, 2, dp[i]);
            continue;
        }
        g = query(0, 1, a + 1, i, d, 0);
        h = query(0, 1, a + 1, i, d, 1);
        if(g - h > b) {
            insert(0, 1, a + 1, i, 2, dp[i]);
            continue;
        }
        dp[i] = 1 + query(0, 1, a + 1, i+c, d + 1, 2);
        insert(0, 1, a + 1, i, 2, dp[i]);
    }
    if(dp[1] > a) dp[1] = -1;
    cout << dp[1] << endl;
}