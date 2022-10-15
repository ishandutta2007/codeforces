#include <iostream>

using namespace std;

int n;
int p[5000+1];
int a, t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > n) {
            t++;
            continue;
        }
        if (p[a]) t++;
        p[a] = 1;
    }
    cout << t << endl;
}