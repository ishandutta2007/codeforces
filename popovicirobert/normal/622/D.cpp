#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int v[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i += 2)
        v[(i + 1) / 2] = v[(i + 1) / 2 + n - i] = i;
    for(i = 2; i < n; i += 2)
        v[n + i / 2] = v[n + i / 2 + n - i] = i;
    for(i = 1; i <= 2 * n; i++) {
        if(v[i] == 0)
            v[i] = n;
        cout << v[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}