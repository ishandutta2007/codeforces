#include <cstdio>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef long long ll;

const int OFF = (1<< 19);
const int N = 3e5 + 500;
const int INF = 0x3f3f3f3f;

struct node{
    ll zr, l, r, sm, lst, lstl;
};

node NULA, tour[2 * OFF], pref, ans;
ll rlans = INF, cnt = 0, ind[N], ind2[N], rll[N];

vector < pair < char, pair < int, int > > > vq;
vector < pair < int, int > > v;

node mrg(node A,node B){
    if(A.sm == NULA.sm) return B;
    if(B.sm == NULA.sm) return A;
    node C;
    C.l = A.l;
    C.r = B.r + max(A.r - B.l - B.zr + 1, 0LL);
    C.sm = A.sm + B.sm;
    C.zr = (C.r - C.l + 1) - C.sm;
    C.lstl = B.lstl;
    if(C.r == B.r && B.lst != -1)
        C.lst = B.lst;
    if(B.lst == -1 || C.r != B.r){
        C.lst = A.lst;
        if(A.r < B.l - 1)
            C.lst = B.l - 1;
    }
    return C;
}

void update(int i,ll x,ll y){
    i += OFF;
    if(x == -1){
        tour[i] = NULA;
    }
    else{
        tour[i].l = x;
        tour[i].r = x + y - 1;
        tour[i].sm = y;
        tour[i].zr = 0;
        tour[i].lstl = x;
        tour[i].lst = -1;
    }
    for(i = i / 2 ; i ; i /= 2)
        tour[i] = mrg(tour[2 * i], tour[2 * i + 1]);
}

void query(int i,ll x){
    if(i >= OFF || tour[i].sm == (ll)INF * INF) return;
    node nw = mrg(ans, tour[2 * i]);
    if(nw.lst >= x || nw.lstl > x){
        query(2 * i, x);
        return;
    }
    ans = mrg(ans, tour[2 * i]);
    query(2 * i + 1, x);
}

int main(){
    NULA.lst = -1;
    NULA.sm = (ll)INF * INF;
    NULA.r = -1;
    for(int i = 0;i<2 * OFF;i++) tour[i] = NULA;
    int q;scanf("%d", &q);
    for(int i = 0;i<q;i++){
        char c;scanf(" %c", &c);
        if(c == '+'){
            int x,y;scanf("%d%d", &x, &y);
            rll[i] = cnt;
            v.push_back({x, cnt++});
            vq.push_back({'+', {x, y}});
        }
        else if(c == '?'){
            int x;scanf("%d", &x);
            vq.push_back({'?', {x, x}});
        }
        else{
            int x;scanf("%d", &x);
            vq.push_back({'-', {x - 1, x - 1}});
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0;i<v.size();i++)
        ind[v[i].Y] = i;
    cnt = 0;
    for(int i = 0;i<q;i++){
        if(vq[i].X == '+'){
            update(ind[cnt++], vq[i].Y.X, vq[i].Y.Y);
        }
        else if(vq[i].X == '-'){
            update(ind[rll[vq[i].Y.X]], -1, -1);
        }
        else{
            ans = NULA;
            query(1, vq[i].Y.X);
            printf("%lld\n", max(ans.r + 1 - vq[i].Y.X, 0LL));
        }
    }
}