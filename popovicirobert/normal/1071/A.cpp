#include <bits/stdc++.h>

using namespace std;

bool vis[1 << 16];
vector <int> arr1, arr2;

inline bool check(int n, int a, int b) {
    if(1LL * n * (n + 1) / 2 > a + b) {
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    arr1.clear();
    arr2.clear();
    for(int i = n; i >= 1; i--) {
        if(a >= i) {
            a -= i;
            arr1.push_back(i);
            vis[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0 && b >= i) {
            b -= i;
            arr2.push_back(i);
        }
    }
    return 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int a, b;
    ios::sync_with_stdio(false);
    cin >> a >> b;
    int res = 0;
    for(int step = 1 << 15; step; step >>= 1) {
        if(check(res + step, a, b)) {
            res += step;
        }
    }
    check(res, a, b);
    cout << arr1.size() << "\n";
    for(auto it : arr1) {
        cout << it << " ";
    }
    cout << "\n" << arr2.size() << "\n";
    for(auto it : arr2) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}