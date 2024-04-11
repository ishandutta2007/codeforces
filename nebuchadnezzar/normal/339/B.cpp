#include <cstdio>
#include <iostream>

using namespace std;

int n, m, num;//, mas[100000];
long long ans;

int main() {
    cin >> n >> m;

    int prev = 1;
    for (int i = 0; i < m; ++i) {
         cin >> num;
         if (prev <= num) {
            ans += num - prev;
         } else {
            ans += n - prev + num;
         }
         //cout << ans << endl;
         prev = num;
    }

    cout << ans;

    return 0;
}