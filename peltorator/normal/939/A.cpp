#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef double ld;

void solve();
bool read();

int main()
{
    while (read())
        solve();
#ifndef ONLINE_JUDGE
	cerr << "\ntime: " << (ll) clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
#endif
    return 0;
}

const int N = 500001;
int a[N];
int n;

bool read()
{
    if (!(cin >> n))
        return 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    return 1;
}

void solve()
{
    for (int i = 1; i <= n; i++)
        if (a[a[a[i]]] == i)
        {
            cout << "YES";
            return;
        }
    cout << "NO";
}