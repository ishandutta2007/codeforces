#include <bits/stdc++.h>

using namespace std;
int n, k;
int a, b;
int t[10001];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> t[i];
    }
    a = 2 * n;
    b = n;
    //cout << a << " " << b << endl;
    for (int i = 1; i <= k; i++) {
        if (t[i] % 2 != 0) {
            //cout << t[i] << "ABC" << endl;
            t[i]--;
            b--;
            a++;
        }
    }
    //cout << a << " " << b << endl;
    for (int i = 1; i <= k; i++) {
        b -= t[i] / 4;
        if (t[i] % 4 == 1 || t[i] % 4 == 2) {
            a--;
        }
    }
    //cout << a << " " << b << endl;
    if (b > 0) {
        a += b / 2 * 3;
        a += b % 2 != 0;
        b = 0;
    }
    if (b < 0) {
        a += 2 * b;
    }
    if (a >=0) {
        cout << "YES" << endl;
    }
    
    else {
        cout << "NO" << endl;
    }
    return 0;
}