#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }   
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int a = b[i] + mx;
        mx = max(mx, a);
        cout << a << ' ';
    }
    cout << endl;
    return 0;
}