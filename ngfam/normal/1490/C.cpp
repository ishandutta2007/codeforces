#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<long long> cubes((int)1e4);
    cubes[0] = -1e18;
    for(int i = 1; i < cubes.size(); ++i) {
        cubes[i] = 1ll * i * i * 1ll * i;
    }

    int ntest; cin >> ntest;
    while(ntest--) {
        bool flag = false;
        long long x; cin >> x;
        
        for(int i = 1; i < cubes.size(); ++i) {
            if (binary_search(cubes.begin(), cubes.end(), x - cubes[i])) {
                flag = true;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}