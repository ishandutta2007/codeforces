#include <iostream>

using namespace std;

// u = x[2]+x[3]
// x[1]+x[2] x[1]+x[3]

int n;
int x[5555];
int u;

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cout << "? 1 " << i << endl;
        cin >> x[i];
    }
    cout << "? 2 3" << endl;
    cin >> u;
    u = (x[2]+x[3]-u)/2;
    cout << "! " << u << " ";
    for (int i = 2; i <= n; i++) cout << x[i]-u << " ";
    cout << endl;
}