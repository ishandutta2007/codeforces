#include <bits/stdc++.h>
using namespace std;

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }

    if (n % 2 != 0)
        cout << "-1";
    else {
        for (int i = 0; i < n-1; i+=2) {
            swap(a[i], a[i+1]);
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }
    return 0;
}