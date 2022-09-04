/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 5e5 + 100, inf = 1e9 + 100;

int n;

int answer[maxn];

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        int x, y, kek1, kek2;
        cin >> x >> y >> kek1 >> kek2;
        x = abs(x);
        y = abs(y);
        if (x % 2 == 0 && y % 2 == 0)
            answer[i] = 1;
        else
        if (x % 2 == 0 && y % 2 == 1)
            answer[i] = 2;
        else
        if (x % 2 == 1 && y % 2 == 0)
            answer[i] = 3;
        else
        if (x % 2 == 1 && y % 2 == 1)
            answer[i] = 4;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << answer[i] << '\n';
}