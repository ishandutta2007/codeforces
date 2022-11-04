#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 

using namespace std;

constexpr ll INF = 1e18;

struct Node {
    ll mn;
    int cnt;

    Node() : mn(INF), cnt(0) {}

    Node(ll mn, int cnt) : mn(mn), cnt(cnt) {}
};

struct SegTree {
    vector<Node> aint;
    int n;

    SegTree(int n) : n(n) {
        int sz = 1;
        while (sz < 2 * n) {
            sz *= 2;
        }
        aint.resize(sz + 1);
    }

    Node combine(const Node& a, const Node& b) {
        Node node;

        node.mn = min(a.mn, b.mn);
        if (a.mn == node.mn) {
            node.cnt += a.cnt;
        }
        if (b.mn == node.mn) {
            node.cnt += b.cnt;
        }

        return node;
    }

    void update(int node, int left, int right, int pos, ll val) {
        if (left == right) {
            aint[node] = Node(val, 1);
        } else {
            int mid = (left + right) / 2;

            if (pos <= mid) update(2 * node, left, mid, pos, val);
            else update(2 * node + 1, mid + 1, right, pos, val);

            aint[node] = combine(aint[2 * node], aint[2 * node + 1]);
        }
    }

    int getRight(int node, int left, int right, int pos, ll val) {
        if (pos <= left) {
            if (aint[node].mn >= val) {
                return -1;
            }

            if (left == right) {
                assert(aint[node].mn < val);
                return left;
            }

            int mid = (left + right) / 2;
            int answer = -1;

            if (aint[2 * node].mn < val) {
                answer = getRight(2 * node, left, mid, pos, val);
            } else {
                answer = getRight(2 * node + 1, mid + 1, right, pos, val);
            }

            return answer;

        } else {
            int mid = (left + right) / 2;
            int answer = -1;

            if (pos <= mid) {
                answer = getRight(2 * node, left, mid, pos, val);
            }
            if (answer == -1 && aint[2 * node + 1].mn < val) {
                answer = getRight(2 * node + 1, mid + 1, right, pos, val);
            }

            return answer;
        }
    }

    Node query(int node, int left, int right, int l, int r) {
        if (l <= left && right <= r) {
            return aint[node];
        } else {
            int mid = (left + right) / 2;
            Node answer;

            if (l <= mid) answer = combine(answer, query(2 * node, left, mid, l, r));
            if (mid < r) answer = combine(answer, query(2 * node + 1, mid + 1, right, l, r));

            return answer;
        }
    }
};



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // a1, a2, a3, a4, a5, a6, a7
    // a1, a2 - a1, a3 - a2 + a1, a4 - a3 + a2 - a1, a5 - a4 + a3 - a2 + a1

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;

        vector<SegTree> st(2, SegTree(n));

        vector<ll> a(n + 1);
        ll answer = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                answer++;
            }

            a[i] -= a[i - 1];        
            st[i & 1].update(1, 1, n, i, a[i]);
        }


        for (int i = 1; i < n; i++) {
            int r1 = st[1 - (i & 1)].getRight(1, 1, n, i + 1, a[i - 1]) - 1;
            int r0 = st[i & 1].getRight(1, 1, n, i + 1, -a[i - 1]) - 1;

            if (r1 == -2) {
                r1 = n;
            }
            if (r0 == -2) {
                r0 = n;
            }

            r0 = r1 = min(r1, r0);
            
            auto q1 = st[1 - (i & 1)].query(1, 1, n, i + 1, r1);
            auto q0 = st[i & 1].query(1, 1, n, i + 1, r0);

            assert(q1.mn >= a[i - 1]);
            assert(q0.mn >= -a[i - 1]);

            if (q1.mn - a[i - 1] == 0) {
                answer += q1.cnt;
            }
            if (q0.mn + a[i - 1] == 0) {
                answer += q0.cnt;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}