#include <iostream>

using namespace std;

int n, k;
int t[1000+1];
int m, p;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (t[k] == 0) m++;
        t[k]++;
        if (t[k] > p) p = t[k];
    }
    cout << p << " " << m << endl;
}