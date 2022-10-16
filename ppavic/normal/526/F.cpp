#include <cstdio>
#include <vector>
#include <stack>

#define X first
#define Y second

using namespace std;

typedef pair < int, int > pii;
typedef long long ll;

const int N = 1e6 + 500;
const int OFF = (1 << 20);
const int INF = 0x3f3f3f3f;

pii tour[2 * OFF + 500];
int prop[2 * OFF + 500], n, q, a[N];

pii mrg(pii A, pii B){
    if(A.X < B.X) return A;
    else if(A.X > B.X) return B;
    return {A.X, A.Y + B.Y};
}

void refresh(int x){
    tour[x].X += prop[x];
    if(x < OFF){
        prop[2 * x] += prop[x];
        prop[2 * x + 1] += prop[x];
    }
    prop[x] = 0;
}

void update(int i,int a,int b,int lo,int hi,int x){
    if(hi < lo) return;
    refresh(i);
    if(lo <= a && b <= hi){
        prop[i] += x;
        refresh(i);
        return;
    }
    if(a > hi || b < lo) return;
    update(2 * i, a, (a + b) / 2, lo, hi, x);
    update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, x);
    tour[i] = mrg(tour[2 * i], tour[2 * i + 1]);
}

pii query(int i,int a,int b,int lo,int hi){
    refresh(i);
    if(lo <= a && b <= hi) return tour[i];
    if(a > hi || b < lo) return {INF, 0};
    return mrg(query(2 * i, a, (a + b) / 2,lo, hi), query(2 * i + 1, (a + b) / 2  + 1, b, lo, hi));
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i<2*OFF;i++) tour[i] = {INF, 0};
    for(int i = OFF;i<OFF+n;i++) tour[i + 1] = {0,1};
    for(int i = OFF - 1; i ; i--) tour[i] = mrg(tour[2 * i], tour[2 * i + 1]);

    for(int i = 0;i<n;i++){
        int x, y;scanf("%d%d", &x, &y);
        a[x] = y;
    }
    stack < pair < int, pii > > stx, sty;
    ll sol = 0;
    for(int i = 1;i<=n;i++){
        int lft = i;
        while(!stx.empty() && stx.top().X < a[i]){
            update(1, 0, OFF - 1, stx.top().Y.X, stx.top().Y.Y, -stx.top().X);
            lft = stx.top().Y.X;
            stx.pop();
        }
        update(1, 0, OFF - 1, lft, i, a[i]);
        stx.push({a[i], {lft, i}});
        lft = i;
        while(!sty.empty() && sty.top().X > a[i]){
            update(1, 0, OFF - 1, sty.top().Y.X, sty.top().Y.Y, sty.top().X);
            lft = sty.top().Y.X;
            sty.pop();
        }
        update(1, 0, OFF - 1, lft, i, -a[i]);
        sty.push({a[i], {lft, i}});
        update(1, 0, OFF - 1, 1, i - 1, -1);
        pii res = query(1, 0, OFF - 1, 1, i);
        sol += (res.X == 0 ? res.Y : 0);
    }
    printf("%lld\n", sol);
    return 0;
}