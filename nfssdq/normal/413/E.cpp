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
#define linf       (1<<60)-1
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

char pp[2][200001];
int nd[2][200001];
pair < int, int > ps[500001];
struct node {
    int s1, e1, s2, e2, dis;
    int l, r;
} ar[200001];
int pre[200001];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    cin >> pp[0] >> pp[1];
    for(int i = 0; i <= 200000; i++){
        ar[i].s1 = ar[i].e1 = ar[i].s2 = ar[i].e2 = -1;
        ar[i].dis = 0; ar[i].l = ar[i].r = -1;
    }
    e = 0; d = 1;
    for(int i = 0; i < a; i++){
        ps[i + 1] = mp(0, i);
        ps[i + a + 1] = mp(1, i);
        if(pp[0][i] == 'X' && pp[1][i] == 'X') c = 0;
        else if(pp[0][i] == 'X' && pp[1][i] == '.') c = 1;
        else if(pp[0][i] == '.' && pp[1][i] == 'X') c = 2;
        else c = 3;
        if(e != c){
            if(e != 0)d++;
            e = c;
            if(c == 0) continue;
            if(pp[0][i] == '.'){
                nd[0][i] = d;
                ar[d].s1 = i;
                ar[d].e1 = i;
            }
            if(pp[1][i] == '.'){
                nd[1][i] = d;
                ar[d].s2 = i;
                ar[d].e2 = i;
            }
        } else if(c != 0) {
            if(pp[0][i] == '.'){
                nd[0][i] = d;
                ar[d].e1 = i;
            }
            if(pp[1][i] == '.'){
                nd[1][i] = d;
                ar[d].e2 = i;
            }
        }
    }
    if(pp[0][a - 1] == '.' || pp[1][a - 1] == '.') d++;
    for(int i = 1; i < d; i++){
        if(i > 1){
            if(ar[i].s1 >= 0 && ar[i -1].e1 == ar[i].s1 - 1)ar[i].l = 0;
            if(ar[i].s2 >= 0 && ar[i -1].e2 == ar[i].s2 - 1)ar[i].l = 1;
        }
        if(i < d - 1){
            if(ar[i].e1 >= 0 && ar[i + 1].s1 == ar[i].e1 + 1)ar[i].r = 0;
            if(ar[i].e2 >= 0 && ar[i + 1].s2 == ar[i].e2 + 1)ar[i].r = 1;
        }
        if(ar[i].l == 0 && ar[i].r == 0) ar[i].dis = 1 + ar[i].e1 - ar[i].s1;
        if(ar[i].l == 0 && ar[i].r == 1) ar[i].dis = 2 + ar[i].e1 - ar[i].s1;
        if(ar[i].l == 1 && ar[i].r == 0) ar[i].dis = 2 + ar[i].e1 - ar[i].s1;
        if(ar[i].l == 1 && ar[i].r == 1) ar[i].dis = 1 + ar[i].e2 - ar[i].s2;
        if(ar[i].l == -1) pre[i] = i;
        else pre[i] = pre[i - 1];
        ar[i].dis += ar[i - 1].dis;
    }
    REP(i, b){
        cin >> c >> d;
        pair < int, int > p1 = ps[c];
        pair < int, int > p2 = ps[d];
        e = nd[p1.xx][p1.yy];
        f = nd[p2.xx][p2.yy];
        if(pre[e] != pre[f]){
            cout << -1 << endl;
            continue;
        }
        if(e > f){
            swap(e, f);
            swap(p1, p2);
        }
        if(e == f){
            cout << abs(p1.xx - p2.xx) + abs(p1.yy - p2.yy) << endl;
            continue;
        }
        g = 0;
        if(e < f - 1) g = ar[f - 1].dis - ar[e].dis;
        g += abs(p1.xx - ar[e].r) + abs(p2.xx - ar[f].l);

        if(p1.xx == 0) g += ar[e].e1 - p1.yy;
        else g += ar[e].e2 - p1.yy;

        if(p2.xx == 0) g += p2.yy - ar[f].s1;
        else g += p2.yy - ar[f].s2;
        cout << g + 1 << endl;
    }
}