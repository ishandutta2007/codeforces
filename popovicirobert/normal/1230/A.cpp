#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i;
    vector <int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    for(int conf = 0; conf < (1 << 4); conf++) {
        int cur = 0;
        for(i = 0; i < 4; i++) {
            if(conf & (1 << i)) {
                cur += a[i];
            }
        }
        if(2 * cur == a[0] + a[1] + a[2] + a[3]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}