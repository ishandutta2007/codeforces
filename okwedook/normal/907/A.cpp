#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() { 
    ll v1, v2, v3, vm;
    cin >> v1 >> v2 >> v3 >> vm;
    vm *= 2;
    for (int i1 = v1; i1 <= 2 * v1; ++i1)
        for (int i2 = v2; i2 <= 2 * v2; ++i2)
            for (int i3 = v3; i3 <= 2 * v3; ++i3) {
                if (i1 > i2 && i2 > i3 && vm < i1 && vm < i2 && vm <= i3 * 2 && vm >= i3) {
                    cout << i1 << endl << i2 << endl << i3 << endl;
                    //system("pause");
                    return 0;
                }
            }
    cout << -1;
    //system("pause");     
    return 0; 
}