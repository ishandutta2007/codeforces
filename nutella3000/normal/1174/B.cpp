#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    bool one = false;
    bool two = false;
    for(int i = 0;i < n;i++) {
        if (a[i] % 2 == 0) one = true;
        else two = true;
    }
    if (!one || !two) {
        for(int i : a) cout << i << " ";
    }else{
        sort(a, a + n);
        for(int i : a) cout << i << " ";
    }
}