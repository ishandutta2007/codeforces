#include <iostream>
#include <algorithm>

using namespace std;

int k;

int main() {
    cin >> k;
    if (k%2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    int p = k/2-1;
    for (int i = 0; i < k; i++) {
        for (int a = 0; a < k; a++) {
            for (int b = 0; b < k; b++) {
                int x = min(min(max(abs(a-p),abs(b-p)),
                            max(abs(a-p-1),abs(b-p))),
                        min(max(abs(a-p),abs(b-p-1)),
                            max(abs(a-p-1),abs(b-p-1))));

                cout << "bw"[(x+i)%2];
            }
            cout << endl;
        }
        cout << endl;
    }
}