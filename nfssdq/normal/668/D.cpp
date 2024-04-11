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


//struct node {
//    int l, r;
//    unordered_map < int, int > um;
//    void node(){
//        l = r = -1;
//        um.clear();
//    }
//};
//
//node seg[100001 * 50];
//int cnt;
//
//void insert(int idx, int s, int e, int p, int v){
//    seg[idx].um[v]++;
//    if(s == e) return;
//    int mid = (s + e) / 2;
//    if(seg[idx].l == -1){
//        seg[cnt] = node();
//        seg[idx].l = cnt;
//        cnt++;
//    }
//    if(seg[idx].r == -1){
//        seg[cnt] = node();
//        seg[idx].r = cnt;
//        cnt++;
//    }
//
//    if(p <= mid){
//        insert(seg[idx].l, s, mid, p, v);
//    }else{
//        insert(seg[idx].r, mid + 1, e, p, v);
//    }
//}
//
//
//int query(int idx, int s, int e, int p){
//    if(s == e){
//        return seg[idx].cnt;
//    }
//    int mid = (s + e) / 2;
//    if(p <= mid){
//        if(seg[idx].l == -1) return 0;
//        return query(seg[idx].l, s, mid, p);
//    }else{
//        if(seg[idx].r == -1) return 0;
//        return query(seg[idx].r, mid + 1, e, p);
//    }
//}

unordered_map < int, int > bit[100001];
void insert(int x, int y){
    for(int i = x; i <= 100000; i += i & -i) bit[i][y]++;
}
int query(int x, int y){
    int ret = 0;
    for(int i = x; i > 0; i -= i & -i) ret += bit[i][y];
    return ret;
}


map < int, int > mm1, mm2;
pair < int, int > pp[100001];
pair < int, int > id[100001];
int res[100001], seg_id[100001];

//set < int > S;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    FOR(i, 1, n+1){
        cin >> id[i].xx >> pp[i].xx >> id[i].yy;
        pp[i].yy = i;

        if(id[i].xx == 2) id[i].yy = -id[i].yy;
        mm1[id[i].yy] = 1;

        if(id[i].xx == 3) mm1[-id[i].yy] = 1;

        mm2[pp[i].xx] = 1;
    }
    int cc = 0;
    for(auto &v: mm1){
        v.yy = ++cc;
    }
    cc = 0;
    for(auto &v: mm2){
        v.yy = ++cc;
    }

//    seg[cnt++] = node();

    FOR(i, 1, n+1){
        if(id[i].xx < 3){
            insert(mm2[pp[i].xx], mm1[id[i].yy]);
        } else {
            int res = query(mm2[pp[i].xx], mm1[id[i].yy]) - query(mm2[pp[i].xx], mm1[-id[i].yy]);
            cout << res << "\n";
        }
    }


}