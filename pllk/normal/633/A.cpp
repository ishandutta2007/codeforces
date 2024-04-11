#include <iostream>

using namespace std;

int a, b, c;
int x[101010];

int main() {
    cin >> a >> b >> c;
    x[0] = 1;
    for (int i = 1; i <= c; i++) {
        if (i-a >= 0 && x[i-a]) x[i] = 1;
        if (i-b >= 0 && x[i-b]) x[i] = 1;
    }
    if (x[c]) cout << "Yes\n";
    else cout << "No\n";
}