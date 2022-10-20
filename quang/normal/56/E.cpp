#include <bits/stdc++.h>
#define fi freopen("Domino.inp", "r", stdin)
#define fo freopen("Domino.out", "w", stdout)

using namespace std;

const int N = 100010;

int n;
pair<int, int> a[N];
int Tree[N * 5];
int d[N];
map <int, int> M;

int Getmax(int node, int l, int r, int x, int y) {
    if(y < l || x > r) return 0;
    if(x <= l && r <= y) return Tree[node];
    int m = (l + r) >> 1;
    int p1 = Getmax(node * 2, l, m, x, y);
    int p2 = Getmax(node * 2 + 1, m + 1, r, x, y);
    return max(p1, p2);
}

void Update(int node, int l, int r, int id, int val) {
    if(id < l || id > r) return;
    if(l == r) {
        Tree[node] = val;
        return;
    }
    int m = (l + r) >> 1;
    Update(node * 2, l, m, id, val);
    Update(node * 2 + 1, m + 1, r, id, val);
    Tree[node] = max(Tree[node * 2], Tree[node * 2 + 1]);
}


int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second, M[a[i].first] = i;
    sort(a + 1, a + n + 1);
    a[n + 1] = make_pair(1000000000, 0);
    for(int i = n; i; i--) {
        int gh = a[i].first + a[i].second - 1;
        int id = M[a[i].first];
        if(a[i + 1].first > gh) d[id] = 1;
        else {
            int vt = upper_bound(a + 1, a + n + 1, make_pair(gh, 1000000000)) - a - 1;
            d[id] = Getmax(1, 1, n, i + 1, vt) - i + 1;
        }
        Update(1, 1, n, i, d[id] + i - 1);
    }
    for(int i = 1; i <= n; i++) cout << d[i] << " ";
    return 0;
}