/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sqrc = 10000;

bool vis[maxn];

int n, k;

int ed[maxn];

vector<int> p;

int ans1, ans2;

int q[maxn];

bitset<maxn> b;

int main(){
    #ifdef ONPC
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    /*n = 1e6, k = 1e6;
    cout << n << ' ' << k << '\n';
    int it = 0;
    for (int sz = 2; it < n; sz++){
        if (it + sz > n)
            sz = n - it;
        for (int i = 0; i < sz - 1; i++)
            cout << it + i + 1 << ' ';
        cout << it + 1 << ' ';
        it += sz;
    }
    return 0;*/
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &ed[i]), ed[i]--;
    for (int i = 0; i < n; i++)
    if (!vis[i]){
        int x = i;
        int y = 0;
        while (!vis[x]){
            y++;
            vis[x] = 1;
            x = ed[x];
        }
        p.push_back(y);
    }
    sort(p.begin(), p.end());
    int kc = k;
    for (int i = 0; i < p.size(); i++)
        if (kc >= p[i] / 2)
            kc -= p[i] / 2, ans2 += p[i] / 2 * 2;
        else{
            ans2 += kc * 2;
            kc = 0;
        }
    for (int i = 0; i < p.size() && kc > 0; i++)
        if (p[i] & 1)
            ans2++, kc--;
    if (p.size() < sqrc){
        b[0] = 1;
        for (int i = 0; i < p.size(); i++)
            b |= b << p[i];
        if (b[k])
            ans1 = k;
        else
            ans1 = k + 1;
        printf("%d %d", ans1, ans2);
        return 0;
    }
    kc = k;
    k = min(k, n - k);
    for (int i = 1; i <= k; i++)
        q[i] = -1;
    int l = 0, r = -1;
    int maxv = 0;
    while (l < p.size()){
        if (p[l] > k)
            break;
        while (r < (int)p.size() - 1 && p[r + 1] == p[l])
            r++;
        int cnt = r - l + 1;
        maxv += cnt * p[l];
        maxv = min(k, maxv);
        for (int i = 1; i <= maxv; i++)
            q[i] = min(q[i], 0);
        int val = p[l];
        for (int i = 0; i + val <= maxv; i++)
            if (q[i] != -1 && q[i] != cnt)
                if (q[i + val] == -1 || q[i + val] > q[i] + 1)
                    q[i + val] = q[i] + 1;
        if (q[k] != -1){
            ans1 = kc;
            break;
        }
        l = r + 1;
    }
    if (q[k] != -1)
        ans1 = kc;
    else
        ans1 = kc + 1;
    printf("%d %d", ans1, ans2);
}