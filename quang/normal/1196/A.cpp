#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long sum = a + b + c;
        cout << sum / 2 << endl;
    }    
    return 0;
}