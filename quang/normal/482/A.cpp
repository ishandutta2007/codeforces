#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n, k;
int cur1, cur2;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> k;
    cur1 = 1;
    cur2 = n;
    for(int i = 1; i < k; i++) {
        if(i % 2) cout << cur1++ << " ";
        else cout << cur2-- << " ";
    }
    if(k % 2 == 0) {
        for(int i = k; i <= n; i++) cout << cur2-- << " ";
    } else {
        for(int i = k; i <= n; i++) cout << cur1++ << " ";
    }
     return 0;
}