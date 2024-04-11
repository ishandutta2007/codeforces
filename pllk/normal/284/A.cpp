#include <iostream>

using namespace std;

int p;
int c;

int main() {
    cin >> p;
    for (int x = 1; x < p; x++) {
        int a = x;
        int v = 0;
        for (int i = 1; i <= p-2; i++) {
            if (a == 1) v = 1;
            a = (a*x)%p;
        }
        if (a != 1) v = 1;
        if (v == 0) c++;
    }
    cout << c << endl;
}