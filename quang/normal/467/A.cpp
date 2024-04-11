#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n, res = 0;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        if(u + 2 <= v) res++;
    }
    cout << res;
    return 0;
}