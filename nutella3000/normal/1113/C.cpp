#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    int b[n];
    b[0] = a[0];
    map<int,int> c1;
    map<int,int> c2;
    c1[b[0]]++;
    c2[0]++;
    for(int i = 1;i < n;i++) {
        b[i] = (b[i - 1] ^ a[i]);
        if (i % 2 == 0) c1[b[i]]++;
        else c2[b[i]]++;
    }
    long long ans = 0;
    for(pair<int,int> i : c1) {
        ans += (long long)i.second * (i.second - 1) / 2;
    }
    for(pair<int,int> i : c2) ans += (long long)i.second * (i.second - 1) / 2;
    cout << ans;
}