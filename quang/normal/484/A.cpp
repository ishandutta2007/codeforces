#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n;
long long l, r;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    while(n--) {
        cin >> l >> r;
        for(int i = 0; i < 62; i++)
            if((l | (1ll << i)) <= r)
                l |= (1ll << i);
        cout << l << endl;
    }
    return 0;
}