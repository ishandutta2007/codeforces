#include <cstdio>
#include <iostream>

using namespace std;
const int MAXN = 305;

int n, num;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (i != n - 1) {
            for (int j = 0; j < num; ++j) {
                cout << "PRL";
            }
            cout << "R";
        } else {
            for (int j = 0; j < num; ++j) {
                cout << "PLR";
            }
        }
    }
    

    return 0;
}