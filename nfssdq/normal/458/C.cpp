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

vector < int > vc[100001];
pair < int, int > p1[100001], p2[100001];
LL nv[100001], sum[100011], cnt[100011];
LL seg[400001], ss[400001];
void insert(int idx, int s, int e, int p){
    if(s == e){
        seg[idx] += p;
        ss[idx]++;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p);
    else insert(idx * 2 + 2, mid + 1, e, p);
    ss[idx]++; seg[idx] += p;
}
LL query(int idx, int s, int e, int p){
//    cout << p << endl;
    if(ss[idx] < p) return linf;
    if(s == e){
        return p*s;
    }
    int mid = (s + e) / 2;
    if(ss[idx * 2 + 1] >= p) return query(idx * 2 + 1, s, mid, p);
    else return query(idx * 2 + 2, mid + 1, e, p - ss[idx * 2 + 1]) + seg[idx * 2 + 1];
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a;
    REP(i, 100001) p2[i].yy = i;
    REP(i, a){
        cin >> b >> c;
        p1[i] = mp(b, c);
        p2[b].xx++;
    }
    sort(p2 + 1, p2 + 100001);
    reverse(p2 + 1, p2 + 100001);
    FOR(i, 1, 100001) nv[p2[i].yy] = i;
    REP(i, a){
        p1[i].xx = nv[p1[i].xx];
        vc[p1[i].xx].pb(p1[i].yy);
    }
    REP(i, 100001) vsort(vc[i]);
    for(int i = 100000; i >= 1; i--){
        cnt[i] = cnt[i + 1];
        sum[i] = sum[i + 1];
        for(int j = 1; j <= 100000; j++){
            if(vc[j].size() < i) break;
            cnt[i]++;
            sum[i] += vc[j][vc[j].size() - i];
            if(i < vc[0].size()) insert(0, 0, 100000, vc[j][vc[j].size() - i]);
        }
    }
    f = linf;
    for(int i = max((LL)vc[0].size(), 1ll); i <= 100000; i++){
        b = sum[i];
        c = cnt[i];
//        cout << b << " " << ((LL)i - (LL)vc[0].size() - c) << " " << c << endl;
        if(((LL)i - (LL)vc[0].size() - c) <= 0) f = min(f, b);
        else {
//            cout << "pppp" << " " << i << endl;
            f = min(f, b + query(0, 0, 100000, ((LL)i - (LL)vc[0].size() - c)));
        }
        for(int j = 1; j <= 100000; j++){
            if(vc[j].size() < i) break;
//            cout << vc[j][i - 1] << endl;
            insert(0, 0, 100000, vc[j][vc[j].size() - i]);
        }
    }
    cout << f << endl;
}