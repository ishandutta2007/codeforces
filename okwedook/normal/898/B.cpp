#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i <= n / a; ++i) {
        if ((n - a * i) % b == 0) {
            cout << "YES\n";
            cout << i << ' ' << (n - a * i) / b;
            //system("pause");
            return 0;
        }
    }
    cout << "NO";
    //system("pause");
    return 0;
}