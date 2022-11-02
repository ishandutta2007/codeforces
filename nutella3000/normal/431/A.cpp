#include<bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif

    int a[4];
    for(int i = 0;i < 4;i++) cin >> a[i];
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0;i < s.size();i++) {
        sum += a[(s[i] - '1')];
    }
    cout << sum;
}