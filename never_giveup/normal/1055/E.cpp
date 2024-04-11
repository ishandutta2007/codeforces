#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
using namespace std;

typedef long long ll;

typedef long double ld;

void setmax(int &x, int y){
    x = max(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

const int maxn = 1600, inf = 1e9 + 100;

int n, seg, need, kth;

int a[maxn];

pair<int, int> q[maxn];

pair<int, int> arr[maxn];

int p[maxn];

pair<int, int> check(int val, int lam){
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + (a[i - 1] <= val);
    for (int i = 1; i <= n; i++)
        q[i].fr = -1;
    for (int i = 0; i < n; i++)
    if (q[i].fr != -1)
        for (int j = 0; j < seg; j++){
            int l = arr[j].fr, r = arr[j].sc;
            if (r >= i)
                q[r + 1] = max(q[r + 1], m_p(q[i].fr + p[r + 1] - p[max(i, l)] + lam, q[i].sc + 1));
        }
    pair<int, int> wow = {0, 0};
    for (int i = 1; i <= n; i++)
        wow = max(wow, q[i]);
    return wow;
}

bool check(int val){
    int l = -n - 1, r = 0;
    while (r - l > 1){
        int M = (l + r) / 2;
        if (check(val, M).sc >= need)
            r = M;
        else
            l = M;
    }
    auto w = check(val, r);
    return w.fr - r * need >= kth;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> seg >> need >> kth;
    vector<int> srt(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], srt[i] = a[i];
    for (int i = 0; i < seg; i++)
        cin >> arr[i].fr >> arr[i].sc, arr[i].fr--, arr[i].sc--;
    sort(srt.begin(), srt.end());
    unique(srt);
    int l = -1, r = srt.size();
    while (r - l > 1){
        int M = (l + r) / 2;
        if (check(srt[M]))
            r = M;
        else
            l = M;
    }
    if (r == srt.size())
        cout << -1;
    else
        cout << srt[r];
}