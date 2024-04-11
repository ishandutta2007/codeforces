#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    int flag = 0;

    if (isPrime(m)) {
        for (int i = n + 1; i <= m - 1; i++) {
            if (isPrime(i)) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "NO";
        else
            cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}