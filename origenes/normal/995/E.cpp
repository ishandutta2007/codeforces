#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

int u, v, p, head = -1;

inline int inc(int a) {
    return (a + 1) % p;
}

inline int dec(int a) {
    return (a + p - 1) % p;
}

int inv(int a) {
    int ret = 1, tot = p - 2;
    while (tot) {
        if (tot & 1) ret = ll(ret) * a % p;
        a = ll(a) * a % p;
        tot >>= 1;
    }
    return ret;
}

queue<int> q[2];
map<int, int> ops[2];
vector<int> op1, op2, ans;

void enq1(int a, int op) {
    if (ops[0].count(a)) return;
    ops[0][a] = op;
    q[0].push(a);
}

void enq2(int a, int op) {
    if (ops[1].count(a)) return;
    ops[1][a] = op;
    q[1].push(a);
    if (ops[0].count(a)) head = a;
}

int main() {
    scanf("%d%d%d", &u, &v, &p);
    q[0].push(u);
    q[1].push(v);
    ops[0][u] = ops[1][v] = 0;
    while (true) {
        int now = q[0].front();
        q[0].pop();
        enq1(inc(now), 2);
        enq1(dec(now), 1);
        enq1(inv(now), 3);
        now = q[1].front();
        q[1].pop();
        enq2(inc(now), 2);
        enq2(dec(now), 1);
        enq2(inv(now), 3);
        if (head != -1) break;
    }
    int st = head, now;
    while (now = ops[0][head]) {
        op1.pb(now);
        switch (now) {
            case 1:
                head = inc(head);
                break;
            case 2:
                head = dec(head);
                break;
            default:
                head = inv(head);
        }
    }
    head = st;
    while (now = ops[1][head]) {
        op2.pb(now);
        switch (now) {
            case 1:
                head = inc(head);
                break;
            case 2:
                head = dec(head);
                break;
            default:
                head = inv(head);
        }
    }
    ROF(i, op1.size() - 1, 0) ans.pb(op1[i]);
    for (const int &cur : op2) {
        if (cur < 3) ans.pb(3 - cur);
        else ans.pb(3);
    }
    printf("%d\n", ans.size());
    for (const int &cur : ans) {
        if (cur < 3) printf("%d ", 3 - cur);
        else printf("%d ", cur);
    }
    puts("");
    return 0;
}