#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    long long prefix[n];

    cin >> a[0];
    prefix[0] = a[0];

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }

    long long c = 0;

    int prefix2[n];

    if (prefix[n-1] == 3 *prefix[0])
        prefix2[0] = 1;
    else
        prefix2[0] = 0;

    for (int i = 1; i < n - 2; i++) {
        if (prefix[n-1] == 3 * prefix[i])
            prefix2[i] = prefix2[i-1] +1;
        else
            prefix2[i] = prefix2[i-1];
    }

    for (int j = 1; j <= n - 2; j++) {
        if (prefix[n-1] == 1.5 * prefix[j])
            c += prefix2[j-1];
    }

    cout << c;

    return 0;
}