#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    long long pos = 1, t = 0;
    
    vector<int> a(m+1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if (a[i] < pos) {
            t += n - pos + a[i];
        }
        else {
            t += a[i] - pos;
        }
        pos = a[i];
    }
    
    cout << t;
    
}