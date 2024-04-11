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
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int seg[4000001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid)insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
int get_lft(int idx, int s, int e, int st, int ed, int v){
    if(seg[idx] > v)return -1;
    if(s == e)return s;
    int mid = (s + e) / 2;
    if(ed <= mid)return get_lft(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid)return get_lft(idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        int r = get_lft(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
        if(r != -1)return r;
        return get_lft(idx * 2 + 1, s, mid, st, mid, v);
    }
}
int get_rgt(int idx, int s, int e, int st, int ed, int v){
    if(seg[idx] > v)return -1;
    if(s == e)return s;
    int mid = (s + e) / 2;
    if(ed <= mid)return get_rgt(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid)return get_rgt(idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        int l = get_rgt(idx * 2 + 1, s, mid, st, mid, v);
        if(l != -1)return l;
        return get_rgt(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
    }
}
int ar[1000001], pos[1000001], fin[1000001];
int bit[1000001];
void b_in(int p, int v){
    for(int i = p; i <= 1000000; i += i & -i)bit[i] += v;
}
int b_qu(int p){
    int ret = 0;
    for(int i = p; i > 0 ; i -= i & -i)ret += bit[i];
    return ret;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f = 0,g,h = 1,x,y,z;
    cin >> a >> b;
    FOR(i, 1, a + 1){
        cin >> ar[i];
        pos[ar[i]] = i;
        insert(0, 1, a, i, ar[i]);
        b_in(i, 1);
    }
    REP(i, b){
        cin >> c;
        fin[c] = 1;
    }
    FOR(i, 1, a + 1){
        if(fin[i] == 1)continue;
        int l, r, p;
        if(b_qu(pos[i] - 1) == 0)p = 1;
        else {
            c = get_lft(0, 1, a, 1, pos[i] - 1, i);
            if(c == -1)p = b_qu(pos[i]);
            else p = b_qu(pos[i]) - b_qu(c);
        }
        if((b_qu(a) - b_qu(pos[i])) == 0) r = p;
        else {
            c = get_rgt(0, 1, a, pos[i] + 1, a, i);
            if(c == -1)r = p + (b_qu(a) - b_qu(pos[i]));
            else r = p + (b_qu(c - 1) - b_qu(pos[i]));
        }
        f += r;
        b_in(pos[i], -1);
        insert(0, 1, a, pos[i], 100000000);
    }
    cout << f << endl;
}