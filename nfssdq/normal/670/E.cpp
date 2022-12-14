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


int seg[2000000];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
}
int queryL(int idx, int s, int e, int st, int ed){
    if(st > ed) return -1;
    if(seg[idx] == 0) return -1;
    if(s == e) return s;
    int mid = (s + e) / 2;
    if(ed <= mid) return queryL(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return queryL(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        int p = queryL(idx * 2 + 1, s, mid, st, mid);
        if(p == -1) return queryL(idx * 2 + 2, mid + 1, e, mid + 1, ed);
        return p;
    }
}
int queryR(int idx, int s, int e, int st, int ed){
    if(st > ed) return -1;
    if(seg[idx] == 0) return -1;
    if(s == e) return s;
    int mid = (s + e) / 2;
    if(ed <= mid) return queryR(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return queryR(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        int p = queryR(idx * 2 + 2, mid + 1, e, mid + 1, ed);
        if(p == -1) return queryR(idx * 2 + 1, s, mid, st, mid);
        return p;
    }
}

stack < int > S;
string s1, s2;
int to[500001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, p; cin >> n >> m >> p >> s1 >> s2;
    p--;
    REP(i, n){
        if(s1[i] == '('){
            S.push(i);
        } else {
            to[S.top()] = i;
            to[i] = S.top();
            S.pop();
        }
    }

    REP(i, n) insert(0, 0, n-1, i, 1);
    REP(i, m){
        if(s2[i] == 'L'){
            int v = queryR(0, 0, n-1, 0, p-1);
            p = v;
        } else if(s2[i] == 'R'){
            int v = queryL(0, 0, n-1, p+1, n-1);
            p = v;
        } else {
            int s = min(to[p], p);
            p = max(to[p], p);
            while(s <= p){
                insert(0, 0, n-1, s, 0);
                if(s == p) break;
                int v = queryL(0, 0, n-1, s + 1, n-1);
                s = v;
            }
            int v = queryL(0, 0, n-1, p + 1, n-1);
            if(v == -1){
                v = queryR(0, 0, n-1, 0, p);
            }
            p = v;
        }
    }
    p = 0;
    while(p != -1){
        int v = queryL(0, 0, n-1, p, n-1);
        if(v == -1) break;
        cout << s1[v];
        p = v + 1;
    }
    cout << endl;
}