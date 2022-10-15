#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    int t = n;
    for (int i = 1; i < n; i++) t += (n-i)*i;
    cout << t << endl;
}