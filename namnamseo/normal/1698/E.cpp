#include <iostream>
#include <vector>
using namespace std;

const int maxn = int(2e5) + 10;
int a[maxn];
int b[maxn];
int ai[maxn];

#define free free_
bool free[maxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

int tc; cin >> tc;
for (;tc--;) {
    int n, s;
    cin >> n >> s;

    fill(free+1, free+n+1, true);

    auto ri = [=](int *a) {
        for (int i=1; i<=n; ++i) a[i] = -1;
        for (int i=1; i<=n; ++i) {
            int x; cin >> x;
            a[x] = i;
        }
    };
    ri(a); ri(b);

    for (int i=1; i<=n; ++i) if (b[i] != -1) free[b[i]] = false;

    for (int i=1; i<=n; ++i) ai[a[i]] = i;
    bool dead = false;
    for (int i=1; i<=n; ++i) if (b[i] != -1) {
        if (i < ai[b[i]]-s) {
            cout << "0\n";
            dead = true;
            break;
        }
    }
    if (dead) continue;

    int fc = 0;
    for (int i=1; i<=s; ++i) if (free[a[i]]) ++fc;

    long long ans = 1;
    const int mod = 998'244'353;
    for (int i=1; i<=n; ++i) {
        if (i+s <= n && free[a[i+s]]) ++fc;

        if (b[i] == -1) {
            (ans *= fc) %= mod;
            --fc;
        }
    }

    cout << ans << '\n';
}

    return 0;
}