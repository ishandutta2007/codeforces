#include <iostream>

using namespace std;

int n;
int t[100000+1];

int main() {
    cin >> n;
    if (n%4 == 2 || n%4 == 3) {
        cout << -1 << endl;
        return 0;
    }
    int a = 0, b = n-1;
    while (b-a+1 >= 4) {
        t[a] = a+2;
        t[a+1] = b+1;
        t[b] = b;
        t[b-1] = a+1;
        a += 2;
        b -= 2;
    }
    if (b-a+1 == 1) {
        t[a] = a+1;
    }
    if (b-a+1 == 3) {
        t[a] = b+1;
        t[a+1] = b;
        t[a+2] = b-1;
    }
    for (int i = 0; i < n; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}