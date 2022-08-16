#include <bits/stdc++.h>
using namespace std;

int maxPieces(int n) {
    int a[5] = {1, 5, 10, 20, 100};
    int j = 4, c = 0;
    
    while (n > 0) {
        c += n / a[j];
        n = n % a[j];
        j -= 1;
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    
    cout << maxPieces(n);
    return 0;
}