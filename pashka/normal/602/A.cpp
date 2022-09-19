#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

// @author: pashka

long long int read();

using namespace std;

int main() {
    long long a = read();
    long long b = read();
//    cout << a << " " << b << endl;
    if (a < b) {
        cout << "<\n";
    } else if (a > b) {
        cout << ">\n";
    } else {
        cout << "=\n";
    }
    return 0;
}

long long int read() {
    int n, b;
    cin >> n >> b;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res = res * b + x;
    }
    return res;
}