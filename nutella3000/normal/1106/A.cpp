#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    int ans = 0;
    for(int i =1;i < n - 1;i++) {
        for(int j = 1;j < n - 1;j++) {
            if (a[i][j] == a[i - 1][j - 1] &&
            a[i][j] == a[i + 1][j - 1]
            && a[i][j] == a[i - 1][j + 1] &&
            a[i][j] == a[i + 1][j + 1]
            && a[i][j] == 'X')ans++;
        }
    }
    cout << ans;
}