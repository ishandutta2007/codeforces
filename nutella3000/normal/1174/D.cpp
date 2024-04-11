#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    bool not_used[1 << 19];
    for(int i = 0;i < (1 << 19);i++) not_used[i] = false;
    for(int i = 1;i < (1 << n);i++) {
        if (!not_used[(x ^ i)] && !not_used[i]) {
            not_used[(x^ i)] = true;
        }
        if (i == x) not_used[x] = true;
    }
    vector<int> pref;
    for(int i = 1;i < (1 << n);i++) {
        if (!not_used[i]) pref.push_back(i);
    }
    cout << pref.size() << '\n';
    int p = 0;
    for(int i : pref) {
        cout << (i ^ p) << " ";
        p = i;
    }
}