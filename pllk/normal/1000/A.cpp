#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> a, b;
int c;

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                a[i] = b[j] = "";
                c++;
                break;
            }
        }
    }
    cout << n-c << "\n";
}