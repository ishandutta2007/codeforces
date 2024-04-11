#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(1339);

const ll llinf = 2e18 + 100;

const int maxn = 2e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 300, LG = 17;

int n;

int p[maxn];

int a, b;

int good(int x){
    return x == a || x == b;
}

int main()
{
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    a--;
    b--;
    if (a > b)
        swap(a, b);
    int rem = n;
    int ans = 0;
    while (rem > 1){
        ans++;
        if (rem == 2){
            cout << "Final!";
            return 0;
        }
        vector<int> q;
        for (int i = 0; i < n; i++)
        if (!p[i])
            q.push_back(i);
        for (int i = 0; i < q.size(); i += 2){
            int x = q[i], y = q[i + 1];
            if (good(x) && good(y)){
                cout << ans;
                return 0;
            }
            if (good(y))
                p[x] = 1;
            else
                p[y] = 1;
        }
        rem /= 2;
    }
}