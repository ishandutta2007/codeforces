#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(1339);

const ll llinf = 2e18 + 100;

const int maxn = 2e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 300, LG = 17;

int n;

int a[maxn];

int ans[3];

int answer;

int A, B, C;

void upd(int x, int y, int z){
    int val = min(x, A) + min(y, B) + min(z, C);
    if (val < answer)
        answer = val, ans[0] = x, ans[1] = y, ans[2] = z;
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
    cin >> n;
    answer = n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (a[0] + 2 != a[n - 1]){
        cout << n << '\n';
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        return 0;
    }
    for (int i = 0; i < n; i++)
    if (a[i] == a[0])
        A++;
    else
    if (a[i] == a[0] + 1)
        B++;
    else
        C++;
    ans[0] = A;
    ans[1] = B;
    ans[2] = C;
    for (int x = 1; x <= B / 2; x++)
        upd(A + x, B - 2 * x, C + x);
    for (int x = 1; x <= min(A, C); x++)
        upd(A - x, B + 2 * x, C - x);
    cout << answer << '\n';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < ans[i]; j++)
            cout << a[0] + i << ' ';
}