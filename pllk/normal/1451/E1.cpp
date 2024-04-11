#include <iostream>

using namespace std;

int read(string what, int a, int b) {
    cout << what << " " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    int n;
    cin >> n;
    int a12 = read("AND",1,2);
    int a13 = read("AND",1,3);
    int a23 = read("AND",2,3);
    int o12 = read("OR",1,2);
    int o13 = read("OR",1,3);
    int x[n+1] {};
    for (int k = 1; k < n; k *= 2) {
        if ((a12&k) && (a13&k) && (a23&k)) {
            x[1] |= k; x[2] |= k; x[3] |= k;
        } else if (a12&k) {
            x[1] |= k; x[2] |= k;
        } else if (a13&k) {
            x[1] |= k; x[3] |= k;
        } else if (a23&k) {
            x[2] |= k; x[3] |= k;
        } else if ((o12&k) && (o13&k)) {
            x[1] |= k;
        } else if (o12&k) {
            x[2] |= k;
        } else if (o13&k) {
            x[3] |= k;
        }
    }
    for (int i = 4; i <= n; i++) {
        int xx = read("XOR",3,i);
        x[i] = x[3]^xx;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << x[i] << " ";
    cout << endl;
}