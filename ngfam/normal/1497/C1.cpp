#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n, k; cin >> n >> k;
        if (n % 3 == 0) cout << n/3 << " " << n/3 << " " << n/3 << endl;
        else if (n%2 == 1) {
            cout << (n-1)/2 << " " << (n-1)/2 << " " << 1 << endl;
        }
        else {
            int m = n / 2;
            if(m%2 == 0) cout << m << " " << m/2 << " " << m/2 << endl;
            else cout << m-1 << " " << m-1 << " " << 2 << endl;
        }
    }

    return 0;
}


/***
 * n le -> ez
 * n chan
 * n/2 chan -> ez
 * n/2 le
 * 
 * 
 * 
 * x, y, z = n/3
 * n % 3 != 1
 * z + 1
 */