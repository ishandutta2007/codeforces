#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e3 + 10;

int n, k, a, b, c, d;

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> k >> a >> b >> c >> d;
    if (n == 4 || k < n + 1){
        cout << -1;
        return 0;
    }
    cout << a << ' ' << c << ' ';
    for (int i = 1; i <= n; i++)
        if (i != a && i != b && i != c && i != d)
            cout << i << ' ';
    cout << d << ' ' << b << '\n';
    cout << c << ' ' << a << ' ';
    for (int i = 1; i <= n; i++)
        if (i != a && i != b && i != c && i != d)
            cout << i << ' ';
    cout << b << ' ' << d << '\n';
}