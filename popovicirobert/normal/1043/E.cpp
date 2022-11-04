#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 3e5;

vector <int> g[MAXN + 1];

struct Data {
    int a, b;
    int pos;
    bool operator <(const Data &other) const {
        return a - b < other.a - other.b;
    }
}arr[MAXN + 1];

ll sa[MAXN + 1], sb[MAXN + 1];
int where[MAXN + 1];

ll sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b;
        arr[i].pos = i;
    }
    sort(arr + 1, arr + n + 1);
    for(i = 1; i <= n; i++) {
        where[arr[i].pos] = i;
        sa[i] = sa[i - 1] + arr[i].a;
        sb[i] = sb[i - 1] + arr[i].b;
    }
    for(i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i = 1; i <= n; i++) {
        int p = arr[i].pos;
        sol[p] = 1LL * arr[i].a * (n - i) + sb[n] - sb[i];
        sol[p] += 1LL * arr[i].b * (i - 1) + sa[i - 1];
        for(auto it : g[p]) {
            if(where[it] <= i) {
                sol[p] -= (arr[where[it]].a + arr[i].b);
            }
            else {
                sol[p] -= (arr[i].a + arr[where[it]].b);
            }
        }
    }
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}