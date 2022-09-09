#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

vector <pii> v;
int n;

bool cmp(pii a, pii b) {
    return mapa(a.ss, a.ff) < mapa(b.ss, b.ff);
}

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        v.puba({a - 1, b - 1});
    }

    sort(bend(v), cmp);

    int end = -100500;
    int ans = 0;
    for (auto p: v) {
        //cerr << p.ff << " " << p.ss << endl;
        if (p.ff > end) {
            end = p.ss;
            ++ans;
        }
    }

    cout << ans << "\n";

    return 0;
}