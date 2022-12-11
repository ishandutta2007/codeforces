#include <algorithm>
#include <iostream>

using namespace std;

const int X = 10;

int s[X], t[X];

int main(void) {

    std::fill(s, s+X, -1);
    std::fill(t, t+X, 0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char com;
        int val;
        cin >> com >> val;

        for (int j = 0; j < X; ++j) {
            const int d = (val >> j) & 1;
            if (com == '|') {
                if (d) {
                    s[j] = 1;
                    t[j] = 0;
                }
            } else if (com == '&') {
                if (!d) {
                    s[j] = 0;
                    t[j] = 0;
                }
            } else if (com == '^') {
                if (d) {
                    t[j] = !t[j];
                }
            }
        }
    }

    int reset = 0;
    int add = 0;
    int x = 0;
    for (int i = 0; i < X; ++i) {
        if (s[i] == -1) {
            reset |= 1 << i;
        }
        if (s[i] == 1) {
            add |= 1 << i;
        }
        if (t[i] == 1) {
            x |= 1 << i;
        }
    }
    
    cout << 3 << endl;
    cout << "& " << reset << endl;
    cout << "| " << add << endl;
    cout << "^ " << x << endl;

    return 0;
}