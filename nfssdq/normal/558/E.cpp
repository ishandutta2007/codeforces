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

int seg[400001][26], lzy[400001][26], fl[400001];
string S;
void build(int idx, int s, int e){
    if(s == e){
        seg[idx][S[s-1]-'a']++;
        return;
    }
    int mid = (s + e) / 2;
    build(idx * 2 + 1, s, mid);
    build(idx * 2 + 2, mid + 1, e);
    REP(i, 26) seg[idx][i] = seg[idx * 2 + 1][i] + seg[idx * 2 + 2][i];
}
void update(int idx, int s, int e){
    if(s == e){
        fl[idx] = 0;
        return;
    }
    int mid = (s + e) / 2;
    int cnt = (mid - s + 1);
    REP(i, 26) lzy[idx * 2 + 1][i] = 0;
    if(fl[idx] == 1){
        REP(i, 26){
            if(lzy[idx][i] >= cnt){
                lzy[idx * 2 + 1][i] = cnt;
                lzy[idx][i] -= cnt;
                break;
            } else {
                lzy[idx * 2 + 1][i] = lzy[idx][i];
                cnt -= lzy[idx][i];
                lzy[idx][i] = 0;
            }
        }
    } else {
        for(int i = 25; i >= 0; i--){
            if(lzy[idx][i] >= cnt){
                lzy[idx * 2 + 1][i] = cnt;
                lzy[idx][i] -= cnt;
                break;
            } else {
                lzy[idx * 2 + 1][i] = lzy[idx][i];
                cnt -= lzy[idx][i];
                lzy[idx][i] = 0;
            }
        }
    }
    REP(i, 26) lzy[idx * 2 + 2][i] = lzy[idx][i];
    REP(i, 26){
        seg[idx * 2 + 1][i] = lzy[idx * 2 + 1][i];
        seg[idx * 2 + 2][i] = lzy[idx * 2 + 2][i];
    }
    fl[idx * 2 + 1] = fl[idx * 2 + 2] = fl[idx];
    fl[idx] = 0;
}
void insert(int idx, int s, int e, int st, int ed, int f, vector < int > vc){
    if(fl[idx]) update(idx, s, e);
    if(s == st && e == ed){
        REP(i, 26){
//            cout << vc[i] << " " << s << " " << e << endl;
            seg[idx][i] = lzy[idx][i] = vc[i];
        }
        fl[idx] = f;
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert(idx * 2 + 1, s, mid, st, ed, f, vc);
    else if(st > mid) insert(idx * 2 + 2, mid + 1, e, st, ed, f, vc);
    else {
        int cnt = mid - st + 1;
        vector < int > vp;
        REP(i, 26) vp.pb(0);
        if(f == 1){
            REP(i, 26){
                if(vc[i] >= cnt){
                    vp[i] = cnt;
                    vc[i] -= cnt;
                    break;
                } else {
                    vp[i] = vc[i];
                    cnt -= vc[i];
                    vc[i] = 0;
                }
            }
        } else {
            for(int i = 25; i >= 0; i--){
                if(vc[i] >= cnt){
                    vp[i] = cnt;
                    vc[i] -= cnt;
                    break;
                } else {
                    vp[i] = vc[i];
                    cnt -= vc[i];
                    vc[i] = 0;
                }
            }
        }
        insert(idx * 2 + 1, s, mid, st, mid, f, vp);
        insert(idx * 2 + 2, mid + 1, e, mid + 1, ed, f, vc);
    }
    REP(i, 26){
        seg[idx][i] = seg[idx * 2 + 1][i] + seg[idx * 2 + 2][i];
    }
}
int char_cnt[30];
void query(int idx, int s, int e, int st, int ed){
    if(fl[idx]) update(idx, s, e);
    if(s == st && e == ed){
        REP(i, 26) char_cnt[i] += seg[idx][i];
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        query(idx * 2 + 1, s, mid, st, mid);
        query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    cin >> S;
    build(0, 1, n);
    while(m--){
        int l, r, f; cin >> l >> r >> f;
        set0(char_cnt);
        query(0, 1, n, l, r);
        vector < int > vc;
        REP(i, 26) {
            vc.pb(char_cnt[i]);
//            cout << vc[i] << endl;
        }
        if(f == 0) f = 2;

        insert(0, 1, n, l, r, f, vc);
    }
    REP(i, n){
        set0(char_cnt);
        query(0, 1, n, i+1, i+1);
        REP(j, 26){
            if(char_cnt[j]) cout << (char)('a'+j);
        }
    }
    cout << endl;
}