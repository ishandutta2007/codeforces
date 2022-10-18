#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    cout << abs(s[a - 1] - s[b - 1]);
    return 0;
}