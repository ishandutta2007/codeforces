#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define sz(a) (int)(a).size()

int a[3], b[3];
vector<int> q;

int f()
{
    return min(a[0], b[0]) + min(a[1], b[1]) + min(a[2], b[2]);
}

int c[3];
int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
        return 1;
    a[0] = a[1] = a[2] = 0;
    q.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> q[i];
    sort(q.begin(), q.end());
    if (q[0] + 2 > q.back())
    {
        cout << n << endl;
        //return 0;
        for (int i : q)
            cout << i << " ";
        cout << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        a[q[i] - q[0]]++;
    b[0] = a[0];
    b[1] = a[1];
    b[2] = a[2];
    int minn = q[0];
    int cur = n;
    while (b[1] > 1)
    {
        b[1] -= 2;
        b[2]++;
        b[0]++;
        if (f() > cur)
        {
            b[1] += 2;
            b[2]--;
            b[0]--;
            break;
        }
        cur = f();
    }
    int cc = f();
    c[0] = b[0];
    c[1] = b[1];
    c[2] = b[2];
    b[0] = a[0];
    b[1] = a[1];
    b[2]=  a[2];
    cur = n;
    while (b[2] > 0 && b[0] > 0)
    {
        b[1] += 2;
        b[0]--;
        b[2]--;
        if (f() > cur)
        {
            b[1] -= 2;
            b[0]++;
            b[2]++;
            break;
        }
        cur = f();
    }
    if (f() > cc)
    {
        b[0] = c[0];
        b[1] = c[1];
        b[2] = c[2];
    }
    cout << f() << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < b[i]; j++)
            cout << minn + i << " ";
    cout << endl;
    return 0;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    for (int i = 1;; i++)
    {
        #ifndef ONLINE_JUDGE
            cerr << "Test #" << i << ":\n";
        #endif // ONLINE_JUDGE
        if (solve())
            break;
        #ifndef ONLINE_JUDGE
            cerr << "____________________________\n";
        #endif // ONLINE_JUDGE
    }
    #ifndef ONLINE_JUDGE
        cerr << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif // ONLINE_JUDGE
    return 0;
}