#include <bits/stdc++.h>
using namespace std;

int T, N, A[1000005];

struct node {
    pair<int, int> p, mn, mx;
    node *l, *r;
    int s, e, m;
    node(int _s, int _e) {
        s = _s;
        e = _e;
        m = (s + e) / 2;
        p = make_pair(A[s], s);
        if (s == e) {
            mn = p;
            mx = p;
            return;
        }
        l = new node(s, m);
        r = new node(m+1, e);
        mn = min(l->mn, r->mn);
        mx = max(l->mx, r->mx);
    }
    pair<int, int> getmx(int qs, int qe) {
        if (qs <= s && e <= qe) return mx;
        else if (s > qe || qs > e) return make_pair(-1000000, -1000000);
        else return max(l->getmx(qs, qe), r->getmx(qs, qe));
    }
    pair<int, int> getmn(int qs, int qe) {
        if (qs <= s && e <= qe) return mn;
        else if (s > qe || qs > e) return make_pair(1000000005, 1000000005);
        else return min(l->getmn(qs, qe), r->getmn(qs, qe));
    }
} *root;

stack< pair<int, int> > S, S2;
int nxtl[1000005], nxtr[1000005];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        while (!S.empty()) S.pop();
        while (!S2.empty()) S2.pop();
        S.push(make_pair(1000000005, N));
        S2.push(make_pair(-1000000000, N));
        for (int i = N-1; i >= 0; i--) {
            while (S.top().first < A[i]) S.pop();
            while (S2.top().first > A[i]) S2.pop();
            nxtl[i] = S.top().second - 1;
            nxtr[i] = S2.top().second - 1;
            S.push(make_pair(A[i], i));
            S2.push(make_pair(A[i], i));
        }
        root = new node(0, N-1);
        int cur = 0, ans = 0;
        while (cur != N-1) {
            if (A[cur] > A[cur+1]) {
                int bot = nxtl[cur];
                //printf("cur: %d, bot: %d\n", cur, bot);
                cur = root->getmn(cur, bot).second;
                ans++;
            } else {
                int bot = nxtr[cur];
                //printf("cur: %d, bot: %d\n", cur, bot);
                cur = root->getmx(cur, bot).second;
                //printf("cur became %d\n", root->getmx(3, 9).second);
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}