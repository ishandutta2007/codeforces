#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, w, h, f[N];
pii Ans[N], anss[N];
struct node {
    int id, swp, op, x, T;
    int metid;
} point[N];
bool cmpGeorge(node aa, node bb) {
    if(aa.metid ^ bb.metid) return aa.metid < bb.metid;
    if(aa.op ^ bb.op) return aa.op < bb.op;
    if(aa.op == 1) return aa.x > bb.x;
    if(aa.op == 2) return aa.x < bb.x;
}
bool cmpegroeG(node aa, node bb) {
    if(aa.metid ^ bb.metid) return aa.metid < bb.metid;
    if(aa.op ^ bb.op) return aa.op > bb.op;
    if(aa.op == 1) return aa.x > bb.x;
    if(aa.op == 2) return aa.x < bb.x;
}
int main() {
    // freopen("ex_bridge2.in", "r", stdin);
    // freopen("ex_bridge2.out", "w", stdout);
    scanf("%d%d%d", &n, &w, &h);
    L(i, 1, n) {
        point[i].id = i;
        scanf("%d%d%d", &point[i].op, &point[i].x, &point[i].T);
        point[i].op = 3 - point[i].op, point[i].metid = point[i].x - point[i].T;
    }
    sort(point + 1, point + n + 1, cmpGeorge);
    point[0].metid = - 1e9 - 114514 - 1919810 - 19260817;
    point[n + 1].metid = 1e9 + 114514 + 1919810 + 19260817;
    L(i, 1, n) point[i].swp = i; // 
    L(i, 1, n) {
        if(point[i].metid == point[i - 1].metid) continue;
        int now = i, cnta = 0, cntb = 0;
        while(now <= n && point[now + 1].metid == point[i].metid) cnta += (point[i].op == 1), cntb += (point[i].op == 2), ++now;
        L(j, i, now) f[j] = point[j].swp;
        sort(point + i, point + now + 1, cmpegroeG);
        L(j, i, now) point[j].swp = f[j];//, cout << f[j] << " ";
        // puts("");
        sort(point + i, point + now + 1, cmpGeorge);
    }
    L(i, 1, n) {
        // cout << point[i].swp << " ";
        if(point[i].op == 1) anss[point[i].swp] = mkp(w, point[i].x);
        else anss[point[i].swp] = mkp(point[i].x, h);
    }
    // puts("");
    L(i, 1, n) Ans[point[i].id] = anss[i];
    L(i, 1, n) printf("%d %d\n", Ans[i].first, Ans[i].second);
    return 0;
}