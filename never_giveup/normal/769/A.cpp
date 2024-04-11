#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    int n, a = 2100, b = 2010;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a = min(a, x);
        b = max(b, x);
    }
    cout << (a + b) / 2;
}