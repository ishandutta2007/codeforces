#include <bits/stdc++.h>

using namespace std;
int n, m, k;
bool jo;
int main()
{
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++) {
        int a, b; cin >> a >> b;
        if (a<=5 || a>=n-4 || b<=5 || b>=m-4) {
            jo=1;
        }
    }
    cout << (jo ? "YES" :"NO");
    return 0;
}