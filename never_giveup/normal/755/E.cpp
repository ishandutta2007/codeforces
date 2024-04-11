/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

int n, k;

int main(){
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> n >> k;
    if (n < 4 || k > 3 || k == 1){
        cout << -1;
        return 0;
    }
    if (k == 2){
        if (n == 4){
            cout << -1;
            return 0;
        }
        cout << n - 1 << '\n';
        for (int i = 1; i < n; i++)
            cout << i << ' ' << i + 1 << '\n';
        return 0;
    }
    cout << 2 + (n - 2) * (n - 3) / 2 << '\n';
    cout << "1 2\n2 3\n";
    for (int i = 2; i < n; i++)
        for (int j = i + 1; j < n; j++)
            cout << i + 1 << ' ' << j + 1 << '\n';
}