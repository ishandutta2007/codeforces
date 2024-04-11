#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

struct Node {
    int a, b, c, l, r;
    Node() {}
    Node(int A, int B, int C, int L, int R) : a(A), b(B), c(C), l(L), r(R) {}
};

int t;
Node node[5000006];
string s;

void construct(int ind, int l, int r) {
    node[ind].l = l;
    node[ind].r = r;
    if (l == r) {
        if (s[l - 1] == '(') node[ind].b = 1;
        else node[ind].c = 1;
        return ;
    }
    int mid = (l + r) / 2;
    construct(ind * 2, l, mid);
    construct(ind * 2 + 1, mid + 1, r);
    int match = min(node[ind * 2].b, node[ind * 2 + 1].c);
    node[ind].a = node[ind * 2].a + node[ind * 2 + 1].a + match;
    node[ind].b = node[ind * 2].b + node[ind * 2 + 1].b - match;
    node[ind].c = node[ind * 2].c + node[ind * 2 + 1].c - match;
}

Node solve(int ind, int l, int r) {
    if (node[ind].r < l || node[ind].l > r) return Node(0, 0, 0, 0, 0);
    if (node[ind].l >=l && node[ind].r <= r) return node[ind];
    int mid = (l + r) / 2;
    Node lNode = solve(ind * 2, l, r);
    Node rNode = solve(ind * 2 + 1, l, r);
    int match = min(lNode.b, rNode.c);
    return Node(lNode.a + rNode.a + match, lNode.b + rNode.b - match, lNode.c + rNode.c - match, 0, 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin >> s >> t;
    construct(1, 1, s.size());
    while (t--) {
        int l, r;
        cin >> l >> r;
        Node tmp = solve(1, l, r);
        cout << 2 * tmp.a << endl;
    }
}