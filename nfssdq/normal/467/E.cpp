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

int seg[2000001];
void insert(int idx, int s, int e, int st, int ed, int v){
    if(s == st && e == ed){
        seg[idx] = min(seg[idx], v);
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid) insert(idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        insert(idx * 2 + 1, s, mid, st, mid, v);
        insert(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
    }
}
int query(int idx, int s, int e, int p){
    if(s == e) return seg[idx];
    int mid = (s + e) / 2;
    if(p <= mid) return min(seg[idx], query(idx * 2 + 1, s, mid, p));
    else return min(seg[idx], query(idx * 2 + 2, mid + 1, e, p));
}
LL dp[500001], ar[500001], mar[500001];
LL best[500001];
vector < int > vc[500001];
map < int, int > mm;
void print(int i, int n){
    if(i > n) return;
    if(best[i] == 0) {
        print(i + 1, n);
        return;
    }
    cout << ar[i] << " " << ar[best[i]] << " " << ar[i] << " " << ar[best[i]] << " ";
    print(best[i] + 1, n);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g = 0,h = 0,x,y,z;
    cin >> a;
    FOR(i, 1, a + 1) {
        cin >> ar[i];
        mm[ar[i]] = 1;
    }
    b = 1;
    for(map<int,int>::iterator it = mm.begin(); it != mm.end(); it++){
        (*it).yy = b++;
    }
    for(int i = 1; i <= a; i++) mar[i] = mm[ar[i]];
    setinf(seg);
    for(int i = a; i >= 1; i--){
        dp[i] = dp[i + 1];
        int cnt = 0;
        for(int j = vc[mar[i]].size() - 1; j >= 0; j--){
            cnt++;
            if(cnt > 3) break;
            c = query(0, 1, a, vc[mar[i]][j]);
            if(c > a) continue;
            if(1 + dp[c + 1] > dp[i]){
                best[i] = c;
                dp[i] = dp[c + 1] + 1;
            }
        }
        if(vc[mar[i]].size() > 0){
            d = vc[mar[i]][vc[mar[i]].size() - 1];
            if(d > i + 1) insert(0, 1, a, i + 1, d - 1, d);
        }
        if(vc[mar[i]].size() > 2){
            d = vc[mar[i]][vc[mar[i]].size() - 3];
            if(1 + dp[d + 1] > dp[i]){
                best[i] = d;
                dp[i] = 1 + dp[d + 1];
            }
        }
        vc[mar[i]].pb(i);
    }
    cout << dp[1]*4 << endl;
    print(1, a);
    cout << endl;
}