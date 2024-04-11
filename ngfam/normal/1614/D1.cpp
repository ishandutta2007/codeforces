#include <bits/stdc++.h>
#define long long long

using namespace std;

const int maxn = 20000001;
const int N = maxn;
vector<int> lp(N+1);
vector<int> pr;

long f[maxn];
int fcount[maxn];
int finalCount[maxn];

void backtrack(int x, int cur, int val) {
    if (x == 1) {
        finalCount[cur] += val;
        return;
    }
    int p = lp[x], cnt = 0;
    while(lp[x] == p) {
        x /= lp[x];
        ++cnt;
    }
    for(int i = 0; i <= cnt; ++i) {
        backtrack(x, cur, val);
        cur *= p;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }

    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        fcount[x]++;
    }


    for(int i = 0; i < maxn; ++i) {
        if (fcount[i]) backtrack(i, 1, fcount[i]);
    }

    for(int i = maxn-1; i >= 1; --i) {
        f[i] = 1ll * i * finalCount[i];
        if (f[i] == 0) continue;
        for(int p: pr) {
            int m = i*p;
            if (m >= maxn) break;
            f[i] = max(f[i], f[m] + 1ll * (finalCount[i] - finalCount[m]) * i);
        }
    }

    cout << f[1] << endl;

    return 0;
}